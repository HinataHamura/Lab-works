`timescale 1ns/1ns

module register_sync_enable_tb;

    reg clk;
    reg reset;
    reg en;
    reg [6:0] d;
    wire [6:0] q;

    // Instantiate the design
    register_sync_enable uut (
        .clk(clk),
        .reset(reset),
        .en(en),
        .d(d),
        .q(q)
    );

    // Clock generation: 20ns period
    always begin
        clk = ~clk;
        #10;
    end

    // Stimulus
    initial begin
        $dumpfile("test.vcd");             
        $dumpvars(0, register_sync_enable_tb);

        // Initial values
        clk = 0;
        reset = 1; en = 0; d = 7'b0000000;

        #15;
        // Release reset, load first value
        reset = 0; en = 1; d = 7'b1010101;

        #20;
        // Change input but disable enable → q should hold
        en = 0; d = 7'b1111111;
        #20;

        // Enable again with new data
        en = 1; d = 7'b0001110;
        #20;

        // Final disable — should hold
        en = 0;
        #20;

        $finish;
    end

    // Monitor changes
    initial begin
        $monitor("Time = %0t | clk = %b | reset = %b | en = %b | d = %b | q = %b",
                 $time, clk, reset, en, d, q);
    end

endmodule
