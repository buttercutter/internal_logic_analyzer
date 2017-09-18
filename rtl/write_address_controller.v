`include "define.v"

module write_address_controller (clk, reset, write_enable, waddr, primed);

input clk, reset, write_enable;

output reg primed = 0;	// to signal whether *all* memory locations have been initialized (written to before) or not
output reg [(`ADDR_WIDTH-1) : 0] waddr = 0;	// address for memory(buffer) writing

always @(posedge clk)
begin
    //$display("{`ADDR_WIDTH{write_enable}} = ", {`ADDR_WIDTH{write_enable}});
    //$display("waddr = %d" , waddr);
    if (reset) 	
	waddr <= 1;
    else
	waddr <= (write_enable) ? (waddr + 1) : waddr;  // if write is enabled, then waddr++
end

always @(posedge clk)
begin
    //$display("primed = ", primed);
    if (reset)	
	primed <= 1'b0;		// memory is not initialized
    else if (!primed) 
	primed <= &waddr;	// the very *first*(!primed) wrapping around (&waddr) of address space 
end

endmodule
