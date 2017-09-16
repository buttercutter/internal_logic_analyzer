// Adapted from http://zipcpu.com/blog/2017/06/02/generating-timing.html and http://www.edaplayground.com/x/2PUP

module reset_gen (clk, reset); // generates a repetitive (2Hz or 500ms = clk/24000000) reset pulse from system clock (clk = 48MHz)

  input clk;
  output reset = ck_stb;
  
  localparam THRESHOLD = 24000000;  // divides i_clk by 24000000 to obtain ck_stb which is just a clock enable signal
  
  reg [($clog2(THRESHOLD)-1):0] counter = 0;
  reg ck_stb = 0;
  
  always @(posedge clk)
  begin
    if(ck_stb)
      counter <= 1;    
    else
      counter <= counter + 1;
    
    //$display("$clog2(THRESHOLD) = ", $clog2(THRESHOLD));
  end
  
  always @(posedge clk)
    ck_stb <= (counter == THRESHOLD-1'b1);
  
endmodule
