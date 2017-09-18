`include "define.v"

module delay (clk, i_data, data);	// simple shift register module to delay for 2 clock cycles 

input clk;
input [(`DATA_WIDTH-1) : 0] i_data;

output reg [(`DATA_WIDTH-1) : 0] data;

reg [(`DATA_WIDTH-1) : 0] shift_reg;

always @(posedge clk)
begin
    shift_reg <= i_data;
    data <= shift_reg;
end

endmodule
