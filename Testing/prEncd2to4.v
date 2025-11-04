// module priority_encoder(input [3:0] in, output [1:0] out);
//   assign out = (in[3]) ? 2'b11 :
//                (in[2]) ? 2'b10 :
//                (in[1]) ? 2'b01 :
//                          2'b00;
// endmodule


// module priority_encoder(input [3:0] in, output reg [1:0] out);
//   always @(*) begin
//     if (in[3]) out = 2'b11;
//     else if (in[2]) out = 2'b10;
//     else if (in[1]) out = 2'b01;
//     else out = 2'b00;
//   end
// endmodule


module priority_encoder_case(
    input  [3:0] Y,       // Y = {Y3, Y2, Y1, Y0}
    output reg [1:0] A
);
    always @(*) begin
        casez (Y)
            4'b1???: A = 2'b11; // Y3 active
            4'b01??: A = 2'b10; // Y2 active
            4'b001?: A = 2'b01; // Y1 active
            4'b0001: A = 2'b00; // Y0 active
            default: A = 2'b00; // All 0
        endcase
    end
endmodule







