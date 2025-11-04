module down_counter_sync (
    input wire clk,
    input wire reset,
    output reg [3:0] q
);

    reg [3:0] r_reg;     // current state (register)
    reg [3:0] r_next;    // next state

    // 1. State Register (memory block)
    always @(posedge clk or posedge reset) begin
        if (reset)
            r_reg <= 4'b1111;       // initialize to 15 on reset
        else
            r_reg <= r_next;        // update on clock
    end

    // 2. Next-State Logic (combinational)
    always @(*) begin
        if (r_reg == 4'd0)
            r_next = 4'b1111;       // wrap around from 0 to 15
        else
            r_next = r_reg - 1;     // normal decrement
    end

    // 3. Output Logic (combinational)
    always @(*) begin
        q = r_reg;
    end

endmodule
