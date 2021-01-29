module lab1_FSM (input fifty, dollar, cancel, clk, rst,
	output reg[1:0] st, output reg insert_coin, money_return, dispense);
	
	// set the constant values which will be the state of the machine
	parameter INIT=2'b00, S50c=2'b01, VEND=2'b10, RETURN=2'b11;
	
	reg [1:0] nst;
	
	always @ *
	begin
		// default values
		nst = st;
		insert_coin = 1;  // tell user that he/she should insert a coin
		money_return = 0;
		dispense = 0;
	
		case(st)
		INIT:
			begin
			     insert_coin = 1;   // set that user need to insert a coin
			     money_return = 0;   // no need to return money
			     dispense = 0;   // no need to dispense item
			
				if (dollar) // item cost 1 dollar so can just dispense item
					nst = VEND;
					
				if (fifty)  // user insert 50 cent only
					nst = S50c;
			end
		S50c:
			begin
			     insert_coin = 1;   // set that user need to insert another coin
			     money_return = 0;   // no need to return money
			     dispense = 0;   // no need to dispense item
			
				if (fifty)  // previously user already inserted 50cent and now insert another 50cent again so can dispense item now
					nst = VEND;
				if (dollar || cancel)   // overshot amount of money inserted or user cancel the operation
					nst = RETURN;
			end
		VEND:
		  begin
		      insert_coin = 0;   // no need to insert anymore money
		      money_return = 0;   // no need to return any money
		      dispense = 1;  // set that can dispense item alread
		  end
		RETURN:
			begin
				nst = INIT; // go back to initial state
				insert_coin = 0;  // no need to insert coin
                money_return = 1;   // set that money needs to be returned to the user
                dispense = 0;   // no need to dispense item
			end
		endcase
	end
	
	always @ (posedge clk)
	begin
		if (rst)
			st <= INIT;
		else
			st <= nst;
	end
endmodule