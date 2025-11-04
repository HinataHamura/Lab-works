module tb_priority_encoder;
    reg [3:0] Y;
    wire [1:0] A;

    // Use one of these:
    // priority_encoder_if uut (.Y3(Y[3]), .Y2(Y[2]), .Y1(Y[1]), .Y0(Y[0]), .A(A));
    priority_encoder_case uut (.Y(Y), .A(A));

    initial begin
        $monitor("Y = %b -> A = %b", Y, A);

        Y = 4'b0000; #10;
        Y = 4'b0001; #10;
        Y = 4'b0010; #10;
        Y = 4'b0100; #10;
        Y = 4'b1000; #10;
        Y = 4'b1100; #10;
        Y = 4'b0110; #10;
        Y = 4'b1010; #10;

        $finish;
    end
endmodule

