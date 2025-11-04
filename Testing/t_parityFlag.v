// parity_flag_tb.v
`timescale 1ns/1ps

module parity_flag_tb;

    reg  [3:0] result;
    wire       PF;

    // Instantiate the module
    parity_flag uut (
        .result(result),
        .PF(PF)
    );

    initial begin
        $display("Time\tResult\tPF");
        $monitor("%g\t%b\t%b", $time, result, PF);

        // Test all 16 combinations of 4-bit inputs
        result = 4'b0000; #10;
        result = 4'b0001; #10;
        result = 4'b0010; #10;
        result = 4'b0011; #10;
        result = 4'b0100; #10;
        result = 4'b0101; #10;
        result = 4'b0110; #10;
        result = 4'b0111; #10;
        result = 4'b1000; #10;
        result = 4'b1001; #10;
        result = 4'b1010; #10;
        result = 4'b1011; #10;
        result = 4'b1100; #10;
        result = 4'b1101; #10;
        result = 4'b1110; #10;
        result = 4'b1111; #10;

        $finish;
    end

endmodule
