`timescale 1ns/1ns

module d_ff_reset_tb;

    reg clk;
    reg reset;
    reg d;
    wire q;

    // Instantiate the D flip-flop with reset
    d_ff_reset circuit1 (clk, reset, d, q);

    // Clock generator: toggles every 10ns
    always begin
        clk = ~clk;
        #10;
    end

    // Stimulus block: test input behavior
    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, d_ff_reset_tb);

        clk <= 0;       // initialize clock
        reset <= 1;     // apply reset
        d <= 0;
        #20;            // wait 20ns with reset active

        reset <= 0;     // release reset
        d <= 1;         // change input
        #20;            // wait 20ns to see q update

        $finish;        // end simulation
    end

    // Monitor changes
    initial begin
        $monitor("Time = %0t | clk = %b | reset = %b | d = %b | q = %b", 
                  $time, clk, reset, d, q);
    end

endmodule
