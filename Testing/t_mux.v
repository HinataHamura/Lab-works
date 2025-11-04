module tb_mux4to1;
  reg [3:0] in;
  reg [1:0] sel;
  wire out;

  mux4to1 uut (.in(in), .sel(sel), .out(out));

  initial begin
    $monitor("in=%b, sel=%b, out=%b", in, sel, out);
    in = 4'b0110;
    sel = 2'b00; #10;
    sel = 2'b01; #10;
    sel = 2'b10; #10;
    sel = 2'b11; #10;
    $finish;
  end
endmodule
