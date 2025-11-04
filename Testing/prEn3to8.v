// module tb_priority_encoder;
//   reg [3:0] in;
//   wire [1:0] out;

//   priority_encoder uut (.in(in), .out(out));

//   initial begin
//     $monitor("in=%b, out=%b", in, out);
//     in = 4'b0000; #10;
//     in = 4'b0001; #10;
//     in = 4'b0010; #10;
//     in = 4'b0100; #10;
//     in = 4'b1000; #10;
//     in = 4'b1100; #10;

//   end
// endmodule

// module priority_encoder_if (
//     input [7:0] D,
//     output reg [2:0] Y
// );

//   always @(*) begin
//     if      (D[7]) Y = 3'b111;
//     else if (D[6]) Y = 3'b110;
//     else if (D[5]) Y = 3'b101;
//     else if (D[4]) Y = 3'b100;
//     else if (D[3]) Y = 3'b011;
//     else if (D[2]) Y = 3'b010;
//     else if (D[1]) Y = 3'b001;
//     else if (D[0]) Y = 3'b000;
//     else           Y = 3'b000;  // default
//   end

// endmodule


module priority_encoder_case (
    input [7:0] D,
    output reg [2:0] Y
);

  always @(*) begin
    casez (D)
      8'b1???????: Y = 3'b111;
      8'b01??????: Y = 3'b110;
      8'b001?????: Y = 3'b101;
      8'b0001????: Y = 3'b100;
      8'b00001???: Y = 3'b011;
      8'b000001??: Y = 3'b010;
      8'b0000001?: Y = 3'b001;
      8'b00000001: Y = 3'b000;
      default:      Y = 3'b000;
    endcase
  end

endmodule