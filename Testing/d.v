module priority_encoder (
    input [7:0] D,
    output [2:0] Y
);

  assign Y = (D[7]) ? 3'b111 :
             (D[6]) ? 3'b110 :
             (D[5]) ? 3'b101 :
             (D[4]) ? 3'b100 :
             (D[3]) ? 3'b011 :
             (D[2]) ? 3'b010 :
             (D[1]) ? 3'b001 :
             (D[0]) ? 3'b000 :
                      3'b000;  // default if all inputs are 0

endmodule


