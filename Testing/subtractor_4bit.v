module subtractor_4bit (
    input wire [3:0] A,
    input wire [3:0] B,
    input wire Bin,
    output wire [3:0] D,
    output wire Bout
);

    wire b1, b2, b3;

    // Connect 4 full subtractors in series
    full_subtractor FS0 (A[0], B[0], Bin,  D[0], b1);
    full_subtractor FS1 (A[1], B[1], b1,   D[1], b2);
    full_subtractor FS2 (A[2], B[2], b2,   D[2], b3);
    full_subtractor FS3 (A[3], B[3], b3,   D[3], Bout);

endmodule
