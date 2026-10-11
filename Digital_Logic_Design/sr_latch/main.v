////    NOR BASED SR LATCH - Combinational Circuit      ////
////  Early Sprints for Digital Logic Design Lesson ////
////         Handcoded by chipmaker 𖢥         ////
module main(input wire R, S, output reg Q, output wire Qn);
	assign Qn = ~Q;
	always @(*) begin
		if (S && !R)	Q = 1'b1;
		else if (!S && R) 	Q = 1'b0;
	end
endmodule
/* display
iverilog -o sim main.v tb_main.v
vvp sim
gtkwave wave.vcd */
////         Handcoded by chipmaker 𖢥         ////
