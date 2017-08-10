`include "define.v"

module stop (clk, reset, waddr, primed, i_trigger, i_holdoff, stopped);

input clk, reset, primed, i_trigger;
input [(ADDR_WIDTH-1) : 0] waddr;
input [(HOLDOFF_WIDTH-1) : 0] i_holdoff;

output reg stopped;

reg triggered;
reg [(HOLDOFF_WIDTH-1) : 0] holdoff_counter = 0;

always @(posedge clk)
begin
    if (reset)	
	triggered <= 1'b0;
    else	
	triggered <= (i_trigger) && (primed);  // Following a reset, once the scope has filled its memory, it enters the PRIMED state. Once it reaches this state, it will be sensitive to i_trigger.
end

always @(posedge clk)
begin
    if ((reset) || !(triggered))	
	holdoff_counter <= 0;
    else 	
	holdoff_counter <= holdoff_counter + (!stopped);   // increments only when memory writing is not stopped
end

always @(posedge clk)
begin
    if ((reset) || !(triggered))	
	stopped <= 0;
    else 	
	stopped <= (holdoff_counter >= i_holdoff); 
end

endmodule
