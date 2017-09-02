`include "define.v"

module delay (clk, i_data, data);	// simple shift register module to delay for 3 clock cycles 

input clk;
input [(`DATA_WIDTH-1) : 0] i_data;

output [(`DATA_WIDTH-1) : 0] data;

reg [(`DATA_WIDTH-1) : 0] shift_reg [1:0];

always @(posedge clk)
begin
    shift_reg[1] <= shift_reg[0];
    shift_reg[0] <= i_data;
end

always @(posedge clk)
begin
    data <= shift_reg[1];
end

endmodule
