module tb_priority_encoder;
    reg [7:0] D;
    wire [2:0] Y;

    // Change module name here to test different versions:
    priority_encoder uut (.D(D), .Y(Y));

    initial begin
        $dumpfile("test.vcd");
        $dumpvars(0,tb_priority_encoder);

        $monitor("D = %b -> Y = %b", D, Y);
        D = 8'b00000000; #10;
        D = 8'b00000001; #10;
        D = 8'b00000010; #10;
        D = 8'b00000100; #10;
        D = 8'b00001000; #10;
        D = 8'b00010000; #10;
        D = 8'b00100000; #10;
        D = 8'b01000000; #10;
        D = 8'b10000000; #10;
        D = 8'b11000000; #10;
        $finish;
    end
endmodule
