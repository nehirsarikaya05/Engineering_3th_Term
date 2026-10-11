`timescale 1ns/1ps

module tb_main;

    wire o1, o2;
    reg  w1, w2;

    main dut (
        .Q(o1),
        .Qn(o2),
        .R(w1),
        .S(w2)
    );

    initial begin
    	$dumpfile("wave.vcd");
        $dumpvars(0, tb_main);
        $monitor("time=%0t | o1=%b o2=%b | w1=%d w2=%b ",
                 $time, o1, o2, w1, w2);
	w1 = 1'd1;  w2 = 1'd0;
	#10;  
	w1 = 1'd0;  w2 = 1'd0;
	#10; 
	w1 = 1'd1;  w2 = 1'd1;
	#10; 
	w1 = 1'd0;  w2 = 1'd1;
	#10; 
	
        $finish;
    end

endmodule
