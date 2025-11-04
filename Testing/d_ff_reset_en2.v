module d_ff_reset_en2 (
    input wire clk,
    input wire reset,
    input wire en,
    input wire d,
    output reg q
);

reg r_next, r_reg;

always @(posedge clk, posedge reset)
begin
    if (reset)
        r_reg <= 1'b0;     // asynchronous reset
    else
        r_reg <= r_next;   // update state at clock edge
end

always @(*)
begin
    if (en)
        r_next = d;        // update with new data
    else
        r_next = r_reg;    // hold previous value
end

always @(*) 
begin
    q = r_reg;
end

endmodule
