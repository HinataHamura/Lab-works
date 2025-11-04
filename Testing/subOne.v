module subOne (
    input wire [3:0] in,
    output wire [3:0] out
);
    assign out = (in == 4'd0) ? 4'd15 : in - 1;
endmodule
