`timescale 1ns/1ns

module mod5_counter_tb;

    reg clk;
    reg reset;
    wire [2:0] q;

    // Instantiate the MOD-5 counter
    mod5_counter uut (
        .clk(clk),
        .reset(reset),
        .q(q)
    );

    // Clock generation: toggle every 10ns
    always #10 clk = ~clk;

    // Test sequence
    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0, mod5_counter_tb);

        clk = 0;
        reset = 1;      // Assert reset
        #15;

        reset = 0;      // Release reset
        #100;           // Let counter run for 5+ cycles

        $finish;
    end

    // Display output
    initial begin
        $monitor("Time = %0t | clk = %b | reset = %b | q = %d", 
                  $time, clk, reset, q);
    end

endmodule
