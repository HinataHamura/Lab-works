`timescale 1ns/1ns

module down_counter_4bit_tb;

    reg clk;
    reg reset;
    wire [3:0] q;

    // Instantiate the counter
    down_counter_4bit uut (
        .clk(clk),
        .reset(reset),
        .q(q)
    );

    // Clock generation: toggle every 10ns
    always #10 clk = ~clk;

    // Stimulus
    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, down_counter_4bit_tb);

        clk = 0;
        reset = 1;    // Apply reset
        #15;

        reset = 0;    // Release reset
        #400;         // Run enough time to observe wrap-around

        $finish;
    end

    // Monitor signal changes
    initial begin
        $monitor("Time = %0t | clk = %b | reset = %b | q = %d", 
                  $time, clk, reset, q);
    end

endmodule
