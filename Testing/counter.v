module counter (
    input wire CLK,
    input wire Reset,
    output wire [6:0] q
);

    wire [6:0] d_temp, q_temp;

    // Register holds the current state
    register register_circuit1 (CLK, Reset, d_temp, q_temp);

    // Adder computes next state = q_temp + 1
    addOne adder_circuit1 (q_temp, d_temp);

    // Output
    assign q = q_temp;

endmodule
