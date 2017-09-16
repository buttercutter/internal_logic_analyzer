module trig_gen (clk, reset, primed, trigger);  // generates a trigger 'pulse'

input clk, reset, primed;
output reg trigger = 0;

reg v1, v2;

always @(posedge clk)
begin
    if(reset) begin
	v1 <= 0;
	v2 <= 0;
	trigger <= 0;
    end

    else begin
	v1 <= primed;
	v2 <= v1;
	trigger <= v1 & ~v2;
    end
end

endmodule
