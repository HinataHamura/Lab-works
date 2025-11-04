// parity_flag.v
module parity_flag (
    input  [3:0] result,   // 4-bit ALU result
    output       PF        // Parity Flag: 1 if even number of 1s
);

    // XOR all bits, then invert to detect even parity
    assign PF = ~(^result);

endmodule
