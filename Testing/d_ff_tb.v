`timescale 1ns/1ns

module d_ff_tb;

    reg clk;
    reg d;
    wire q;

    // Instantiate the D Flip-Flop (Unit Under Test)
    d_ff circuit1 (clk, d, q);

  //This toggles the clock every 10ns → makes a 20ns clock period.
    always begin
        clk = ~clk;
        #10;
    end

    // Stimulus block: provide values to d and clk
    initial begin
        $dumpfile("test.vcd");          // VCD output file
        $dumpvars(0, d_ff_tb);          // Dump all signals in module

        clk <= 0;                       // Initialize clock to 0
        d <= 0;                         // Set input d = 0
        #20;                            // Wait 20 ns

        d <= 1;                         // Set d = 1
        #20;                            // Wait 20 ns
   

        $finish;                        // End simulation
    end

    // Monitor output: shows real-time changes in simulation
    initial begin
        $monitor("Time = %0t | clk = %b | d = %b | q = %b", $time, clk, d, q);
    end

endmodule
