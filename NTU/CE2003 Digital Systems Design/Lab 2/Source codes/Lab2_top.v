`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 24.02.2021 13:58:32
// Design Name: 
// Module Name: Lab2_top
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
// Own created module by SoulX
//////////////////////////////////////////////////////////////////////////////////


module Lab2_top(
    input clk,
    input rst,
    input write_en,
    input save_data,
    input show_reg,
    input [7:0] d_in,
    output [7:0] d_out
    );
    
    reg [7:0] reg_d;    // input for Lab2_mem from d_in
    wire [7:0] mem_d;   // output from Lab2_mem
    
    // instantiate IP module from "Distributed Memory Generator" in "Memories and Storage Elements" > "RAMs & ROMs"
    Lab2_mem l2_mem (
      .a(d_in[5:0]),      // input wire [5 : 0] a
      .d(reg_d),      // input wire [7 : 0] d
      .clk(clk),  // input wire clk
      .we(write_en),    // input wire we
      .spo(mem_d)  // output wire [7 : 0] spo
    );
    
    // implementing a register
    always @ (posedge clk)
    begin
        if (rst)
            reg_d <= 8'd0;
        else if (save_data)
            reg_d <= d_in;
    end
    
    // implement a multiplexer to determine which results to use as output of this module
    assign d_out = show_reg ? mem_d : reg_d;
    
endmodule
