`timescale 1ns/1ns

module down_counter_4bit_tb;

    reg clk;
    reg reset;
    wire [3:0] q;

    down_counter_4bit uut (
        .clk(clk),
        .reset(reset),
        .q(q)
    );

    always #10 clk = ~clk;

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, down_counter_4bit_tb);

        clk = 0;
        reset = 1;
        #15;

        reset = 0;
        #200;

        $finish;
    end

    initial begin
        $monitor("Time = %0t | clk = %b | reset = %b | q = %d",
                  $time, clk, reset, q);
    end

endmodule
