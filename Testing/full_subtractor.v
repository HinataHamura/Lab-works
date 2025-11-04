module full_subtractor (
    input wire A,
    input wire B,
    input wire Bin,
    output wire D,
    output wire Bout
);

    // Difference bit
    assign D = A ^ B ^ Bin;

    // Borrow-out logic
    assign Bout = (~A & B) | ((~(A ^ B)) & Bin);

endmodule
