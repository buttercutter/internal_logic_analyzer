`include "define.v"

module data_gen (clk, reset, data);   // generates 'data' which is basically an incrementing counter

input clk, reset;
output reg [(`DATA_WIDTH-1) : 0] data = 0;

always @(posedge clk)
begin
    if(reset)
	data <= 1;  // starts from 1 instead of 0
    else 
	data <= data + 1;
end

endmodule
