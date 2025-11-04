`timescale 1ns/1ns

module d_ff_reset_en_tb;

    reg clk;
    reg reset;
    reg en;
    reg d;
    wire q;

    // Instantiate the D FF with reset and enable
    d_ff_reset_en circuit1 (clk, reset, en, d, q);

    // Clock generation: toggles every 10ns (20ns period)
    always begin
        clk = ~clk;
        #10;
    end

    // Stimulus block
    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, d_ff_reset_en_tb);

        clk <= 0;
        reset <= 1;   // Assert reset
        en <= 0;
        d <= 0;
        #20;          // Wait 20ns (reset is active)

        reset <= 0;   // Deactivate reset
        en <= 1;      // Enable data loading
        d <= 1;       // Set data input
        #20;

        $finish;      // End simulation
    end

    // Real-time signal monitoring
    initial begin
        $monitor("Time=%0t | clk=%b | reset=%b | en=%b | d=%b | q=%b", 
                  $time, clk, reset, en, d, q);
    end

endmodule
