`include "define.v"

module read_address_controller (clk, reset, read_enable, waddr, raddr);

input clk, reset, read_enable;
input [(`ADDR_WIDTH-1) : 0] waddr;  // we needs write pointer to calculate the read pointer
output reg [(`ADDR_WIDTH-1) : 0] raddr;

reg [(`ADDR_WIDTH-1) : 0] this_addr = 0;

always @(posedge clk)
begin
    //$display("this_addr = %d" , this_addr);
    if (reset)
	this_addr <= 0;
    else 
	this_addr <= (read_enable) ? (this_addr + 1) : this_addr;	// if read is enabled, then this_addr++
end

always @(posedge clk)
begin
    raddr <= this_addr + waddr;// + 1;// + `ADDR_WIDTH'(read_enable);	// raddr (read pointer) starts at the next waddr (write pointer).  if read is enabled, raddr is incremented by '1' (pre-compute the next read pointer)
    //$display("raddr = %d" , raddr);
end						

endmodule
