module main(input wire R, S, output reg Q, output wire Qn);
	assign Qn = ~Q;
	always @(*) begin
		if (S && !R)	Q = 1'b1;
		else if (!S && R) 	Q = 1'b0;
	end
endmodule
