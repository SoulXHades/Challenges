`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 24.02.2021 15:37:41
// Design Name: 
// Module Name: Lab2_top_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// Created by SoulX
//////////////////////////////////////////////////////////////////////////////////


module Lab2_top_tb();

    reg show_reg, write_en, clk, save_data, rst;    // inputs to module to be tested
    reg [7:0] d_in; // inputs to module to be tested
    wire [7:0] d_out;   // output of module to be tested
    
    // instantiate module that is to be tested
    Lab2_top l2_top(.show_reg(show_reg), .write_en(write_en), .clk(clk), 
        .save_data(save_data), .rst(rst), .d_in(d_in), .d_out(d_out));
        
    // creating a clock with 10 time unit per cycle
    always #5 clk = ~clk;
    
    // test bench stimulation section
    initial 
    begin
        show_reg = 1'b0; write_en = 1'b0; clk = 1'b0; save_data = 1'b0; rst = 1'b1; d_in = 8'd0;
        
        #10 rst = 0;
        #10 d_in = 8'h15;
        #10 save_data = 1;
        #10 save_data = 0; d_in = 8'h01;
        #10 write_en = 1;
        #10 write_en = 0;
        #10 d_in = 8'hA3;
        #10 save_data = 1;
        #10 save_data = 0; d_in = 8'h02;
        #10 write_en = 1;
        #10 write_en = 0;
        #10 d_in = 8'h87;
        #10 save_data = 1;
        #10 save_data = 0;
        #10 d_in = 8'h01;
        #10 show_reg = 1;
        #10 d_in = 8'h01; show_reg = 0;
        #10 $finish();
    end

endmodule
