`timescale 1ns/1ns

module reg16bit_tb;

    reg clk;
    reg rst;
    reg [15:0] d;
    wire [15:0] q;

    // Instantiate the 16-bit register
    reg16bit uut (
        .clk(clk),
        .rst(rst),
        .d(d),
        .q(q)
    );

    // Clock generator: toggle every 10ns (20ns period)
    always begin
        clk = ~clk;
        #10;
    end

    // Stimulus
    initial begin
        $dumpfile("test.vcd");             
        $dumpvars(0, reg16bit_tb);

        // Initialize signals
        clk = 0;
        rst = 1;
        d = 16'h0000;
        #15;

        // Release reset, apply first value
        rst = 0;
        d = 16'hAAAA;     // Alternating bits (1010101010101010)
        #20;

        // Change data again
        d = 16'h5555;     // Inverse pattern (0101010101010101)
        #20;

        // Assert reset again
        rst = 1;
        #20;

        // Deassert reset and set new data
        rst = 0;
        d = 16'hF0F0;     // New pattern
        #20;

        $finish;
    end

    // Monitor output
    initial begin
        $monitor("Time=%0t | clk=%b | rst=%b | d=%h | q=%h", 
                  $time, clk, rst, d, q);
    end

endmodule
