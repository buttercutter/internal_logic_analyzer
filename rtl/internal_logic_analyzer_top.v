// Adapted from http://zipcpu.com/blog/2017/06/08/simple-scope.html

`include "define.v"

module internal_logic_analyzer_top(clk, reset, i_trigger, i_holdoff, i_data, o_data, o_primed);  // Used to **log** or write internal FPGA signals into memory

input clk, reset, i_trigger;   	// clock, reset(to signal start writing) and trigger(to signal stop writing) input signals
input [(`HOLDOFF_WIDTH-1) : 0] i_holdoff;	// a programmable user holdoff value that determines how much more to write upon receiving trigger signal before stopping memory write
input [(`DATA_WIDTH-1) : 0] i_data;	// connected to internal FPGA signals of interest
output[(`DATA_WIDTH-1) : 0] o_data;	// to be viewed using gtkwave
output o_primed;	// '1' indicates memory has been initialized, '0' indicates otherwise

wire [(`ADDR_WIDTH-1) : 0] raddr;	// memory read pointer
wire [(`ADDR_WIDTH-1) : 0] waddr;	// memory write pointer
wire stopped; 	// just a stop flag for stopping memory writing
wire [(`DATA_WIDTH-1) : 0] data_delayed;   // to hold the delayed data stream

// Implements the memory reading and writing mechanisms
memory_block mem (.clk(clk), .write_enable(!stopped), .waddr(waddr), .raddr(raddr), .data_write(data_delayed), .data_read(o_data));

// Manages the memory write pointer
write_address_controller wr (.clk(clk), .reset(reset), .write_enable(!stopped), .waddr(waddr), .primed(o_primed)); 

// Manages the memory read pointer
read_address_controller rd (.clk(clk), .reset(reset), .read_enable(stopped), .waddr(waddr), .raddr(raddr));

// Determines when to (stop writing and then start reading)
stop st (.clk(clk), .reset(reset), .primed(o_primed), .i_trigger(i_trigger), .i_holdoff(i_holdoff), .stopped(stopped));

// Adjust the delay for data stream so the triggered and stopped signal lie in the right place, So that when the memory writer stops writing, it stops writing on the correct value.  i.e. A phase calibration
delay dly (.clk(clk), .i_data(i_data), .data(data_delayed));

endmodule

