module down_counter_4bit (
    input wire clk,
    input wire reset,
    output reg [3:0] q
);

    always @(posedge clk or posedge reset) begin
        if (reset)
            q <= 4'b1111;       // Initialize to 15 on reset
        else if (q == 4'd0)
            q <= 4'b1111;       // Wrap around to 15
        else
            q <= q - 1;         // Decrement
    end

endmodule
