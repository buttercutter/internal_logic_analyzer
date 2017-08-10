// Adapted from http://zipcpu.com/blog/2017/06/08/simple-scope.html

`include "define.v"

module internal_logic_analyzer(clk, reset, i_trigger, i_holdoff, i_data, o_data);  // Used to **log** or write internal FPGA signals into memory

input clk, reset, i_trigger;   	// clock, reset(to signal start writing) and trigger(to signal stop writing) input signals
input [(`HOLDOFF_WIDTH-1) : 0] i_holdoff;	// a programmable user holdoff value that determines how much more to write upon receiving trigger signal before stopping memory write
input [(`DATA_WIDTH-1) : 0] i_data;	// connected to internal FPGA signals of interest
output[(`DATA_WIDTH-1) : 0] o_data;	// to be viewed using gtkwave

wire [(`ADDR_WIDTH-1) : 0] waddr;	// memory address for writing purpose
wire primed;	// '1' indicates memory has been initialized, '0' indicates otherwise
wire stopped; 	// just a stop flag for stopping memory writing

reg [(`DATA_WIDTH-1) : 0] ram [(`MEMORY_SIZE-1) : 0]; 	// memory used as circular buffer

// Writing into a slightly modified circular buffer with no read pointer concept
write_mem wr (.clk(clk), .reset(reset), .write_enable(!stopped), .i_data(i_data), .waddr(waddr), .memory(ram), .primed(primed)); 

// Reading from a slightly modified circular buffer with no read pointer concept
read_mem rd (.clk(clk), .reset(reset), .read_enable(stopped), .waddr(waddr), .memory(ram), .o_data(o_data));

// Determines when to (stop writing and then start reading)
stop st (.clk(clk), .reset(reset), .waddr(waddr), .primed(primed), .i_trigger(i_trigger), .i_holdoff(i_holdoff), .stopped(stopped));

endmodule

