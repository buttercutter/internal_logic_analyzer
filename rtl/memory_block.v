`include "define.v"

module memory_block (clk, write_enable, waddr, raddr, data_write, data_read);

input clk, write_enable;
input [(`ADDR_WIDTH-1) : 0] waddr;
input [(`ADDR_WIDTH-1) : 0] raddr;
input [(`DATA_WIDTH-1) : 0] data_write;  // data to be written into memory
output reg [(`DATA_WIDTH-1) : 0] data_read;  // data read out from memory

reg [(`DATA_WIDTH-1) : 0] memory [(`MEMORY_SIZE-1) : 0];

always @(posedge clk)
begin
    if (write_enable)	
    	memory[waddr] <= data_write;
end

always @(posedge clk)
begin
    data_read <= memory[raddr];
end

endmodule
