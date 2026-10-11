module top_module(input [7:0] data_2, input [7:0] data_1, 
 		output wire [7:0] result, output wire evidence);
    assign result   = data_2 - data_1;
    assign evidence = (result == ~data_1);	
endmodule

/* ÇALIŞTIRMA
iverilog -o sim top_module.v tb_top_module.v
vvp sim
gtkwave wave.vcd */

