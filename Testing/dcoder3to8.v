// module decoder3to8(input [2:0] in, input en, output [7:0] out);
//   assign out = en ? (1 << in) : 8'b00000000;
// endmodule


// module decoder3to8(input [2:0] in, input en, output reg [7:0] out);
//   always @(*) begin

//       if (en == 0) out = 8'b00000000;
//       else if (in == 3'b000) out = 8'b00000001;
//       else if (in == 3'b001) out = 8'b00000010;
//       else if (in == 3'b010) out = 8'b00000100;
//       else if (in == 3'b011) out = 8'b00001000;
//       else if (in == 3'b100) out = 8'b00010000;
//       else if (in == 3'b101) out = 8'b00100000;
//       else if (in == 3'b110) out = 8'b01000000;
//       else out = 8'b10000000;     
//     end

// endmodule


module decoder3to8(input [2:0] in, input en, output reg [7:0] out);
  always @(*) begin
      case ({en,in})
        4'b1000: out = 8'b00000001;
        4'b1001: out = 8'b00000010;
        4'b1010: out = 8'b00000100;
        4'b1011: out = 8'b00001000;
        4'b1100: out = 8'b00010000;
        4'b1101: out = 8'b00100000;
        4'b1110: out = 8'b01000000;
        4'b1111: out = 8'b10000000;
        default: out = 8'b00000000;
      endcase
  end
endmodule
