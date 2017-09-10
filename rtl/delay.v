`include "define.v"

module delay (clk, reset, i_data, data);	// simple shift register module to delay for 2 or 3 clock cycles 

input clk, reset;
input [(`DATA_WIDTH-1) : 0] i_data;

output [(`DATA_WIDTH-1) : 0] data;

reg [(`DATA_WIDTH-1) : 0] shift_reg [1:0];
reg had_reset_before = 0;

always @(posedge clk)
begin

    //$display("shift_reg[1] = %d" , shift_reg[1]);
    //$display("shift_reg[0] = %d" , shift_reg[0]);

    shift_reg[1] <= shift_reg[0];
    shift_reg[0] <= i_data;
end

always @(posedge clk)
begin
    if (reset || had_reset_before) begin
	data <= shift_reg[1];
    end

    else
    	data <= shift_reg[0];
end

always @(posedge clk)
begin
    if (reset)
	had_reset_before <= 1'b1;
end

endmodule
