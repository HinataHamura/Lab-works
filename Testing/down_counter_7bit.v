module down_counter_7bit (
    input wire clk,
    input wire reset,
    output reg [6:0] q
);

    always @(posedge clk or posedge reset) begin
        if (reset)
            q <= 7'd127;       // Initialize to 127 (max value for 7 bits)
        else if (q == 7'd0)
            q <= 7'd127;       // Wrap back to 127
        else
            q <= q - 1;        // Decrement
    end

endmodule
