`include "define.v"

module signal_gen (clk, primed, data, trigger, reset);

input clk, primed;
output trigger, reset;
output [(`DATA_WIDTH-1) : 0] data;

reset_gen rg (.clk(clk), .reset(reset));  // generates 'reset'

data_gen dg (.clk(clk), .reset(reset), .data(data));   // generates 'data'

trig_gen tg (.clk(clk), .reset(reset), .primed(primed), .trigger(trigger));  // generates 'trigger'

endmodule
