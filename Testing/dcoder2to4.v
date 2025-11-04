module decoder2to4
(
   input [1:0] A,
   input E,
   output reg [3:0] Y
);
//    assign Y[3] = E & A[1] & A[0];
//    assign Y[2] = E & A[1] & ~A[0];
//    assign Y[1] = E & ~A[1] & A[0];
//    assign Y[0] = E & ~A[1] & ~A[0];

// always @* 
// begin
//     if(E == 1'b0)
//         Y = 4'b0000;
//     else if (A == 2'b00)
//         Y = 4'b0001;
//     else if (A == 2'b01)
//         Y = 4'b0010;
//     else if (A == 2'b10)
//         Y = 4'b0100;
//     else
//         Y = 4'b1000;
// end

always @* 
begin
    case({E,A})
        3'b100: Y = 4'b0001;
        3'b101: Y = 4'b0010;
        3'b110: Y = 4'b0100;
        3'b111: Y = 4'b1000;
        default: Y = 4'b0000; 
    endcase
end


endmodule
