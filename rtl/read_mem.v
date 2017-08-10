`include "define.v"

module read_mem (clk, reset, read_enable, waddr, memory, o_data);

input clk, reset, read_enable;
input [(ADDR_WIDTH-1) : 0] waddr;
input [(DATA_WIDTH-1) : 0] memory [(MEMORY_SIZE-1) : 0];

output reg [(DATA_WIDTH-1) : 0] o_data;

reg [(ADDR_WIDTH-1) : 0] raddr = 0;
reg [(ADDR_WIDTH-1) : 0] this_addr;

always @(posedge clk)
begin
    if (reset)
	raddr <= 0;
    else 
	raddr <= raddr + read_enable;	// if read is enabled, then raddr++
end

always @(posedge clk)
begin
    this_addr <= raddr + waddr + read_enable;	// this_addr (read pointer) starts at the next waddr (write pointer).  if read is enabled, this_addr is incremented by '1' (pre-compute the next read pointer)
    o_data <= memory[this_addr];
end						

endmodule
