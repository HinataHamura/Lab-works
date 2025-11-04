module reg16bit (
    input clk,
    input rst,
    input [15:0] d,
    output reg [15:0] q
);
    always @(posedge clk, posedge rst) 
    begin
        if (rst)
            q <= 16'b0;
        else
            q <= d;
    end
endmodule
