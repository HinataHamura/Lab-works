`timescale 1ns/1ns

module d_ff_reset_en2_tb;

    reg clk;
    reg reset;
    reg en;
    reg d;
    wire q;

    // Instantiate the DUT (Device Under Test)
    d_ff_reset_en2 uut (
        .clk(clk),
        .reset(reset),
        .en(en),
        .d(d),
        .q(q)
    );

    // Clock generation: 10ns high, 10ns low = 20ns period
    always begin
        clk = ~clk;
        #10;
    end

    // Stimulus
    initial begin
        $dumpfile("test.vcd");          // For GTKWave
        $dumpvars(0, d_ff_reset_en2_tb);

        // Initialize
        clk = 0;
        reset = 1; en = 0; d = 0;
        #15;

        // Release reset
        reset = 0;
        en = 1; d = 1;  // Expect q = 1 on next clk ↑
        #20;

        en = 0; d = 0;  // q should hold (not update)
        #20;

        en = 1; d = 0;  // Expect q = 0 on clk ↑
        #20;

        $finish;
    end

    // Monitor signal changes
    initial begin
        $monitor("Time = %0t | clk = %b | reset = %b | en = %b | d = %b | q = %b",
                  $time, clk, reset, en, d, q);
    end

endmodule
