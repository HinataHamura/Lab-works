`timescale 1ns/1ns

module up_counter_4bit_tb;

    reg clk;
    reg reset;
    wire [3:0] q;

    up_counter_4bit uut (
        .clk(clk),
        .reset(reset),
        .q(q)
    );

    // Generate clock (toggle every 10 ns)
    always #10 clk = ~clk;

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, up_counter_4bit_tb);

        clk = 0;
        reset = 1;      // Apply reset
        #15;

        reset = 0;      // Release reset
        #200;           // Allow enough time for wraparound

        $finish;
    end

    initial begin
        $monitor("Time = %0t | clk = %b | reset = %b | q = %d",
                 $time, clk, reset, q);
    end

endmodule
