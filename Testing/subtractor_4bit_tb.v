`timescale 1ns/1ns

module subtractor_4bit_tb;

    reg [3:0] A, B;
    reg Bin;
    wire [3:0] D;
    wire Bout;

    subtractor_4bit uut (
        .A(A),
        .B(B),
        .Bin(Bin),
        .D(D),
        .Bout(Bout)
    );

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, subtractor_4bit_tb);

        $display(" A    -   B    =   D     Bout");
        $display("-----------------------------");

        Bin = 0;

        A = 4'b0111; B = 4'b0010; #10;  // 7 - 2
        A = 4'b0100; B = 4'b0100; #10;  // 4 - 4
        A = 4'b0001; B = 4'b0011; #10;  // 1 - 3 (negative: borrow out = 1)
        A = 4'b1000; B = 4'b0010; #10;  // 8 - 2
        A = 4'b0000; B = 4'b0001; #10;  // 0 - 1

        $finish;
    end

    initial begin
        $monitor("%4b - %4b = %4b   Bout = %b", A, B, D, Bout);
    end

endmodule
