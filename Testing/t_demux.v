module tb_demux1to4;
  reg in;
  reg [1:0] sel;
  wire [3:0] out;

  demux1to4 uut (.in(in), .sel(sel), .out(out));

  initial begin
    $monitor("in=%b, sel=%b, out=%b", in, sel, out);
    in = 3;
    sel = 2'b00; #10;
    sel = 2'b01; #10;
    sel = 2'b10; #10;
    sel = 2'b11; #10;   
  end
endmodule
