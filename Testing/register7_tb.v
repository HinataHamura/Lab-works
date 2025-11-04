`timescale 1ns/1ns

module register_tb;
	reg clk;
	reg reset;
	reg [6:0] d;
	wire [6:0] q;

register circuit1 (clk, reset, d, q);

always begin
	clk = ~clk;
	#10;
end

initial begin
   $dumpfile("test.vcd");
   $dumpvars(0, register_tb);

	clk <= 0;
	reset <= 1;
	d <= 7'b0000_000;
	#20;

	reset <= 0;
	d <= 7'b0000_111;
	#20;

	$finish;
end

initial begin
	$monitor("Time = %0t, clk = %b, reset = %b, d = %b, q = %b", $time, clk, reset, d, q);
end


endmodule
