#include <verilated.h>          // Defines common routines
#include "Vtest_internal_logic_analyzer_top.h"

#include "verilated_vcd_c.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

#define TEST test_internal_logic_analyzer_top__DOT__

// HALF_48MHz_PERIOD = 10416.7ps or 10.4167ns is half of clock period for 48MHz
#define HALF_48MHz_PERIOD 10416.672
#define DEBUG_ENABLED   1/*(num_of_clk_passed >= 2 && num_of_clk_passed <= 6) || (num_of_clk_passed  >= 1020 && num_of_clk_passed <= 1038)*/
#define debug_time	(num_of_clk_passed <= 10)
#define	TRACE_POSEDGE	if ((tfp != NULL) && debug_time) tfp->dump(time_ps*10)
#define	TRACE_NEGEDGE	if ((tfp != NULL) && debug_time) tfp->dump(time_ps*10)
#define	TRACE_FLUSH	if ((tfp != NULL) && debug_time) tfp->flush()
#define	TRACE_CLOSE	if (tfp != NULL) tfp->close()

Vtest_internal_logic_analyzer_top *uut;                     // Instantiation of module
VerilatedVcdC* tfp = NULL;

vluint64_t time_ps = 0;       // Current simulation time

static const unsigned int MEMORY_SIZE = 8;		// size of circular buffer

static int num_of_clk_passed = 0;  // for checking buffer counter data correctness

 
double sc_time_stamp () {       // Called by $time in Verilog
    return time_ps;           // converts to double, to match
    // what SystemC does
}

void update_clk(void) {
	cout << endl << "Start of next clock cycle !" << endl;
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
	cout << "Clock Updated !" << endl;
}

void cout_debug_msg() 
{
    cout << "uut->o_data = " << (int)uut->test_internal_logic_analyzer_top__DOT__o_data << " , num_of_clk_passed = " << num_of_clk_passed << endl;  
    cout << "uut->i_data = " << (int)uut->test_internal_logic_analyzer_top__DOT__data << endl;
    cout << "uut->o_primed = " << (int)uut->test_internal_logic_analyzer_top__DOT__primed << endl; 
    cout << "triggered = " << (int)uut->test_internal_logic_analyzer_top__DOT__ILA__DOT__st__DOT__triggered << endl;
    cout << "stopped = " << (int)uut->test_internal_logic_analyzer_top__DOT__ILA__DOT__stopped << endl;
    cout << "waddr = " << (int)uut->test_internal_logic_analyzer_top__DOT__ILA__DOT__waddr << endl;
    cout << "raddr = " << (int)uut->test_internal_logic_analyzer_top__DOT__ILA__DOT__raddr << endl;
    cout << "this_addr = " << (int)uut->test_internal_logic_analyzer_top__DOT__ILA__DOT__rd__DOT__this_addr << endl;
    cout << "shift_reg = " << (int)uut->test_internal_logic_analyzer_top__DOT__ILA__DOT__dly__DOT__shift_reg << endl;
    cout << "data_delayed = " << (int)uut->test_internal_logic_analyzer_top__DOT__ILA__DOT__data_delayed << endl;
    cout << "i_trigger = " << (int)uut->test_internal_logic_analyzer_top__DOT__trigger << endl;

// for debugging/development purpose only
// print_buffer_data

    const unsigned int ENTRIES_PER_LINE = 25;
    cout << "Printing buffer data !" << endl;
    for (int k=0; k<MEMORY_SIZE; k++)
    {
	if (k==ENTRIES_PER_LINE) cout << endl;
	cout << uut->test_internal_logic_analyzer_top__DOT__ILA__DOT__mem__DOT__memory[k] << " ";
    }
    cout << endl;
}


int main(int argc, char** argv)
{
    // turn on trace or not?
    bool vcdTrace = false;

    Verilated::commandArgs(argc, argv);   // Remember args
    uut = new Vtest_internal_logic_analyzer_top;   // Create instance

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

    while (!Verilated::gotFinish())
    { 
	update_clk();            // Time passes...	

	if(DEBUG_ENABLED) cout_debug_msg();

	if (uut->test_failed) break;
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
