`timescale 1ns/1ns

module counter_tb;

    reg clk;
    reg reset;
    wire [6:0] q;

    counter counter_circuit1(clk, reset, q);

    always begin
        clk = ~clk;
        #10;
    end

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, counter_tb);

        clk <= 0;
        reset <= 1;
        #20;

        reset <= 0;   // Start counting
        #20;
        #20;
        #20;
        #20;

        $finish;
    end

    initial begin
        $monitor("Time = %0t, clk = %b, reset = %b, q = %b", $time, clk, reset, q);
    end

endmodule
