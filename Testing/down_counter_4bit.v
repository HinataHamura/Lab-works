module down_counter_4bit (
    input wire clk,
    input wire reset,
    output wire [3:0] q
);

    wire [3:0] current_q;
    wire [3:0] next_q;

    // Instantiate register
    register_4bit reg_inst (
        .clk(clk),
        .reset(reset),
        .d(next_q),
        .q(current_q)
    );

    // Instantiate subtractor
    subOne sub_inst (
        .in(current_q),
        .out(next_q)
    );

    // Output
    assign q = current_q;

endmodule
