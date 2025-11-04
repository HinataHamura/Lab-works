`timescale 1ns/1ns

module down_counter_7bit_tb;

    reg clk;
    reg reset;
    wire [6:0] q;

    down_counter_7bit uut (
        .clk(clk),
        .reset(reset),
        .q(q)
    );

    // Clock generation (toggle every 10 ns)
    always #10 clk = ~clk;

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, down_counter_7bit_tb);

        clk = 0;
        reset = 1;    // Reset to 127
        #15;

        reset = 0;    // Start counting down
        #300;         // Observe multiple steps

        $finish;
    end

    initial begin
        $monitor("Time = %0t | clk = %b | reset = %b | q = %b | q = %d", 
                 $time, clk, reset, q, q);
    end

endmodule
