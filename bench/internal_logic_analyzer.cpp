#include <verilated.h>          // Defines common routines
#include "Vinternal_logic_analyzer_top.h"

#include "verilated_vcd_c.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

// HALF_48MHz_PERIOD = 10416.7ps or 10.4167ns is half of clock period for 48MHz
#define HALF_48MHz_PERIOD 10416.672
#define debug_time	(time_ps > 9.0071e+15) && (time_ps <= 9.0082e+15)
#define	TRACE_POSEDGE	if ((tfp != NULL) && debug_time) tfp->dump(time_ps*10)
#define	TRACE_NEGEDGE	if ((tfp != NULL) && debug_time) tfp->dump(time_ps*10)
#define	TRACE_FLUSH	if ((tfp != NULL) && debug_time) tfp->flush()
#define	TRACE_CLOSE	if (tfp != NULL) tfp->close()

Vinternal_logic_analyzer_top *uut;                     // Instantiation of module
VerilatedVcdC* tfp = NULL;

vluint64_t time_ps = 0;       // Current simulation time

static const double BUFFER_SIZE = 1024;
static double num_of_clk_passed = 0;  // for checking buffer counter data correctness

double sc_time_stamp () {       // Called by $time in Verilog
    return time_ps;           // converts to double, to match
    // what SystemC does
}

void update_clk(void) {

	uut->clk = 0; 
	uut->eval(); 
	TRACE_NEGEDGE; 

	time_ps = time_ps + HALF_48MHz_PERIOD/2;  

	/*******************************************/

	uut->clk = 1; 
	uut->eval(); 
	TRACE_POSEDGE; 

	time_ps = time_ps + HALF_48MHz_PERIOD; 

	/*******************************************/

	uut->clk = 0; 
	uut->eval(); 
	TRACE_NEGEDGE; 

	time_ps = time_ps + HALF_48MHz_PERIOD/2;

	TRACE_FLUSH;

	num_of_clk_passed++;
}

void cout_debug_msg() 
{
    cout << "uut->o_data = " << uut->o_data << " , num_of_clk_passed = " << num_of_clk_passed << endl;  
    cout << "uut->o_primed = " << (int)uut->o_primed << endl; 
}

bool test_buffer()
{
    if ((num_of_clk_passed >= BUFFER_SIZE) && (num_of_clk_passed <= 2*BUFFER_SIZE)) {
    	// test for counter data correctness in the circular buffer
    	if (uut->o_data != (num_of_clk_passed-1)) {	
	    cout << "Data in the circular buffer is not correct for buffer items at " << (fmod(num_of_clk_passed , (BUFFER_SIZE+1))) << endl;
	    return false;
    	}    
    }

    if (num_of_clk_passed < BUFFER_SIZE) {
        // test for primed condition
    	if (!((int)uut->o_primed) && (uut->i_trigger) && (uut->i_holdoff == 0)) {
	    cout << "Memory is not yet fully initialized. Scope could not stop recording at this point of time" << endl;
	    return false;
	}
    }

    // test for trigger location
    //if () {
	//return false;
    //}

    return true;
}

int main(int argc, char** argv)
{
    // turn on trace or not?
    bool vcdTrace = false;

    Verilated::commandArgs(argc, argv);   // Remember args
    uut = new Vinternal_logic_analyzer_top;   // Create instance

    uut->eval();

    if (vcdTrace)
    {
        Verilated::traceEverOn(true);

        tfp = new VerilatedVcdC;
        uut->trace(tfp, 99);

        std::string vcdname = argv[0];
        vcdname += ".vcd";
        std::cout << vcdname << std::endl;
        tfp->open(vcdname.c_str());
    }

    unsigned int counter = 0;  // this is the test signal we are going to record into circular buffer

    uut->i_holdoff = 0;//BUFFER_SIZE/2;
    uut->clk = 0;
    uut->eval();

    while (!Verilated::gotFinish())
    { 
	counter = counter + 1;
	uut->i_data = counter;
	uut->i_trigger = (num_of_clk_passed == BUFFER_SIZE) ? 1 : 0;	

	update_clk();            // Time passes...

   	cout_debug_msg();

	// test for correct recording operation by reading out the data in circular buffer after (BUFFER_SIZE)th clock cycles
	bool buffer_is_ok = test_buffer();

	if (!(buffer_is_ok) || (num_of_clk_passed == 2*BUFFER_SIZE)) break;
	
    }

    uut->final();               // Done simulating

    if (tfp != NULL)
    {
        tfp->close();
        delete tfp;
    }

    delete uut;

    return 0;
}
