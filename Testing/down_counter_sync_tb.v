`timescale 1ns/1ns

module down_counter_sync_tb;

    reg clk;
    reg reset;
    wire [3:0] q;

    // Instantiate the counter
    down_counter_sync uut (
        .clk(clk),
        .reset(reset),
        .q(q)
    );

    // Generate clock with 20ns period
    always #10 clk = ~clk;

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, down_counter_sync_tb);

        clk = 0;
        reset = 1;       // Apply reset
        #15;

        reset = 0;       // Release reset
        #200;            // Run to observe full cycle and wraparound

        $finish;
    end

    // Monitor output
    initial begin
        $monitor("Time = %0t | clk = %b | reset = %b | q = %d", 
                  $time, clk, reset, q);
    end

endmodule
