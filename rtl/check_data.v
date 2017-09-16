`include "define.v"

module check_data (clk, data_out, data_in, test_failed);  // verifying the memory (circular buffer) read and write processes

input clk;
input [(`DATA_WIDTH-1) : 0] data_out;  // memory output
input [(`DATA_WIDTH-1) : 0] data_in;   // memory input

output reg test_failed = 0;

wire data_out_is_valid;

always @(posedge clk)
begin
    if(((data_out + `MEMORY_SIZE + `ALIGNMENT_DELAY + 1) != data_in) && data_out_is_valid)  // due to "delay.v"
	test_failed <= 1;
end

assign data_out_is_valid = (data_in > `USER_HOLDOFF + `MEMORY_SIZE + `ALIGNMENT_DELAY + 1) && 
			   (data_in <= `MEMORY_SIZE + `MEMORY_SIZE + `USER_HOLDOFF + `ALIGNMENT_DELAY + 1);

endmodule
