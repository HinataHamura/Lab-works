module d_ff 
(
    input wire clk,
    input wire d,
    output reg q  //It's declared as reg because it will hold state and is updated inside an always block.
);

always @(posedge clk) // posedge = positive clock edge
begin
    q <= d;   // “On the rising edge of clk, set q to the value of d.”
end
    
endmodule
