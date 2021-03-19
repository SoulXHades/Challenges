`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:58:13 09/06/2019 
// Design Name: 
// Module Name:    AM_top 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module AM_top (input clk, rst, input [5:0] a, b, output reg [11:0] result);

    // NOTE: Task 3's implementation just follow the diagram on Figure 5

	//reg [5:0] a_r, b_r;  // For task 1 and 2. Removed during task 3
	reg [5:0] a_r1, a_r2, b_r1, b_r2;  // for task 3
	reg [9:0] Pin; // for task 3's multB
	//wire [11:0] P;  // For task 1 and 2. Removed during task 3
	wire [9:0] Pa;     // For task 3
	wire [11:0] Pb;    // For task 3

	// Instantiate the array multiplier
	//array_mult_6bit uut (.a(a_r), .b(b_r), .P(P));   // For task 1 and 2. Removed during task 3
	multA mA (.a(a_r1), .b(b_r1), .P(Pa));    // For task 3
	multB mB (.a(a_r2), .b(b_r2), .Pin(Pin), .P(Pb));     // For task 3
	
	always @ (posedge clk)
		if (rst)		// a positive edge triggered reset.
		begin
//			a_r <= 0;  // For task 1 and 2. Removed during task 3
//			b_r <= 0;  // For task 1 and 2. Removed during task 3
            a_r1 <= 0;  // For task 3
            a_r2 <= 0;  // For task 3
            b_r1 <= 0;  // For task 3
            b_r2 <= 0;  // For task 3
			result <= 0;

		end
		else
		begin
//			a_r <= a;  // For task 1 and 2. Removed during task 3
//			b_r <= b;  // For task 1 and 2. Removed during task 3
//			result <= P;   // For task 1 and 2. Removed during task 3
            a_r1 <= a;  // For task 3
            b_r1 <= b;  // For task 3
            Pin <= Pa;  // For task 3
            a_r2 <= a_r1;   // For task 3
            b_r2 <= b_r1;   // For task 3
            result <= Pb;   // For task 3
		end

endmodule
