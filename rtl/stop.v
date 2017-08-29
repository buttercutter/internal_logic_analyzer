`include "define.v"

module stop (clk, reset, primed, i_trigger, i_holdoff, stopped);

input clk, reset, primed, i_trigger;
input [(`HOLDOFF_WIDTH-1) : 0] i_holdoff;

output reg stopped;

reg triggered;
reg [(`HOLDOFF_WIDTH-1) : 0] holdoff_counter = 0;

always @(posedge clk)
begin
    if (reset)	
	triggered <= 1'b0;
    else begin
	triggered <= (i_trigger) && (primed);  // Following a reset, once the scope has filled its memory, it enters the PRIMED state. Once it reaches this state, it will be sensitive to i_trigger.
	$display("i_trigger = " , i_trigger);
	$display("triggered = " , triggered);
    end
end

always @(posedge clk)
begin
    if (reset)	
	holdoff_counter <= 0;
    else 	
	holdoff_counter <= holdoff_counter + `HOLDOFF_WIDTH'(triggered);   // starts counter only after scope is triggered
end

always @(posedge clk)
begin
    if (reset) // || !(triggered))	
	stopped <= 0;
    else begin
	stopped <= (holdoff_counter >= i_holdoff) && (triggered); 
	$display("stopped = " , stopped);
    end
end

endmodule
