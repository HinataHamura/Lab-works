module mod5_counter (
    input wire clk,
    input wire reset,
    output reg [2:0] q  // 3 bits are enough to store values 0 to 4
);

    always @(posedge clk or posedge reset) begin
        if (reset)
            q <= 3'b000;             // Reset to 0
        else if (q == 3'd4)
            q <= 3'b000;             // Wrap around to 0
        else
            q <= q + 1;              // Increment count
    end

endmodule
