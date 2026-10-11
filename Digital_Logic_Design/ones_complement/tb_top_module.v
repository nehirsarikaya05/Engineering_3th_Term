`timescale 1ns/1ps

module tb_top_module;

    reg [7:0] x1;
    reg [7:0] x2;
    wire y1;
    wire [7:0] y2;

    top_module dut (
        .data_1(x1),
        .data_2(x2),
        .result(y2),
        .evidence(y1)
    );

    initial begin
    	$dumpfile("wave.vcd");
        $dumpvars(0, tb_top_module);
        $monitor("time=%0t | x1=%b x2=%b | y1=%d y2=%b ",
                 $time, x1, x2, y1, y2);
	x1 = 8'd96;  x2 = 8'd255;
	#10;  
	x1 = 8'd41;  x2 = 8'd255;
	#10;
	x1 = 8'd71;  x2 = 8'd255;
	#10;
	x1 = 8'd41;  x2 = 8'd255;
	#10;
	x1 = 8'd200; x2 = 8'd100;
	#10;
	
        $finish;
    end

endmodule
