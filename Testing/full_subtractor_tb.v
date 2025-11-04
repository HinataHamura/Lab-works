`timescale 1ns/1ns

module full_subtractor_tb;

    // Testbench signals
    reg A, B, Bin;
    wire D, Bout;

    // Instantiate the full subtractor module
    full_subtractor uut (
        .A(A),
        .B(B),
        .Bin(Bin),
        .D(D),
        .Bout(Bout)
    );

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, full_subtractor_tb);
        
        // Display header
        $display(" A B Bin | D Bout");
        $display("---------|--------");

        // Apply all input combinations
        A = 0; B = 0; Bin = 0; #10;
        A = 0; B = 0; Bin = 1; #10;
        A = 0; B = 1; Bin = 0; #10;
        A = 0; B = 1; Bin = 1; #10;
        A = 1; B = 0; Bin = 0; #10;
        A = 1; B = 0; Bin = 1; #10;
        A = 1; B = 1; Bin = 0; #10;
        A = 1; B = 1; Bin = 1; #10;

        $finish;
    end

    // Monitor outputs
    initial begin
        $monitor(" %b %b  %b  | %b   %b", A, B, Bin, D, Bout);
    end

endmodule
