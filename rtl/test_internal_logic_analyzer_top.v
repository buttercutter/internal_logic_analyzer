`include "define.v"

module test_internal_logic_analyzer_top(clk, test_failed);

input clk;
output test_failed;

wire reset, trigger, primed;
wire [(`DATA_WIDTH-1) : 0] data;
wire [(`DATA_WIDTH-1) : 0] o_data;

// logic scope
internal_logic_analyzer_top ILA (.clk(clk), .reset(reset), .i_trigger(trigger), .i_holdoff(`USER_HOLDOFF), .i_data(data), .o_data(o_data), .o_primed(primed));

// test signal generator
signal_gen SIG (.clk(clk), .primed(primed), .data(data), .trigger(trigger), .reset(reset));

// verify memory output against memory input
check_data CHKD (.clk(clk), .data_out(o_data), .data_in(data), .test_failed(test_failed));

endmodule
