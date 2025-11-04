module register_sync_enable (
    input wire clk,
    input wire reset,
    input wire en,
    input wire [6:0] d,
    output wire [6:0] q
);

    // 1. Declare state and next-state
    reg [6:0] q_reg;
    wire [6:0] q_next;

    // 2. State Register (with asynchronous reset)
    always @(posedge clk or posedge reset) begin
        if (reset)
            q_reg <= 7'b0000000;
        else
            q_reg <= q_next; // only updated if en=1 inside next-state logic
    end

    // 3. Next-State Logic (synchronous enable)
    assign q_next = en ? d : q_reg;

    // 4. Output Logic
    assign q = q_reg;

endmodule
