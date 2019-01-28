#ifndef SECONDARY
#define SECONDARY
#include "Includer.h"
#include "Game.h"
#include "Tertiary.h"
void Land(Start_return &f, struct board &board, int dice_roll);

void Print_Money(Start_return f) {
	for (int i = 0; i < f.num_of_players; i++) {
		cout << board.player[i].name << ": $" << board.player[i].money << "    ";
	}
	cout << "Free Parking: $:" << board.properties[20].prize << "\n----------------------------------------------\n";
}
Roll_return Init_Roll(Start_return &f) {
	int die1 = rand() % 5 + 1;
	int die2 = rand() % 5 + 1;
	int dice_roll = die1 + die2;
	int roll = 1;
	cout << "Press Enter to Roll";
	cin.ignore();
	cin.ignore();
	system("cls");
	Print_Money(f);
	cout << board.player[f.f].name << " rolled " << dice_roll << endl;
	Roll_return result = { roll, dice_roll, die1, die2 };
	return result;
}
Roll_return Doubles(Start_return &f, struct board &board, int &roll) {
	cout << "You rolled doubles! Roll again" << endl;
	Sleep(1000);
	cout << "Press Enter to Roll";
	cin.ignore();
	system("cls");
	Print_Money(f);
	int die1 = rand() % 5 + 1;
	int die2 = rand() % 5 + 1;
	int dice_roll = die1 + die2;
	roll += 1;
	cout << board.player[f.f].name << " rolled " << dice_roll << endl;
	Sleep(1000);
	Roll_return result = { roll, dice_roll, die1, die2 };
	return result;
}
void GTJ(Start_return &f, struct board &board) {
	cout << "You fucked up, you saggin ass nigga. Time to go to Jail!" << endl;
	Sleep(1000);
	board.player[f.f].jail = 1;
	cout << board.player[f.f].name << " was thrown into the back of a squad car and was sent off to Jail." << endl;
	board.player[f.f].position = 10;
}
void Neg_2s(Start_return &f, struct board &board) {
	Comms(f);
	Chance(f);
	if (board.player[f.f].position == 4) { //Income Tax
		int i_tax = round(board.player[f.f].money*.1);
		int i_tax_choice;
		cout << "Would you like to pay $200 or 10% ($" << i_tax << ")?\n" << "1 - $200\n2 - 10%\n";
		cin >> i_tax_choice;
		while ((i_tax_choice != 1) && (i_tax_choice != 2)) {
			cout << "Would you like to pay $200 or 10% ($" << i_tax << ")?\n" << "1 - $200\n2 - 10%\n";
			cin >> i_tax_choice;
		}
		if (i_tax_choice == 1) {
			board.player[f.f].money -= 200;
			board.properties[20].prize += 200;
		}
		if (i_tax_choice == 2) {
			board.player[f.f].money -= i_tax;
			board.properties[20].prize += i_tax;
		}
	}
	else if (board.player[f.f].position == 20) {//Free Parking
		board.player[f.f].money += board.properties[20].prize;
		cout << "You received $" << board.properties[20].prize << endl;
		board.properties[20].prize = 500;
	}
	else if (board.player[f.f].position == 30) {//Go to Jail
		cout << "Well looks like you got caught in a Monopoly scandal. Time to go to Jail." << endl;
		board.player[f.f].position = 10;
		board.player[f.f].jail = 2;
		
	}
	else if (board.player[f.f].position == 38) {//Luxury Tax
		board.player[f.f].money -= 75;
		board.properties[20].prize += 75;
		cout << "You paid $75. You live the luxurious life." << endl;
	}
}
void Neg_1s(Start_return &f, struct board &board) {
	char buy;
	cout << "Would you like to buy " << board.properties[board.player[f.f].position].name << "?" << endl;
	cout << "B - Buy\nP - Pass\n";
	cin >> buy;
	while ((buy != 'B') && (buy != 'P')) {
		cout << "Invalid, please choose again.  ";
		Sleep(2000);
		system("cls");
		Print_Money(f);
		cout << "Would you like to buy " << board.properties[board.player[f.f].position].name << "for " << board.properties[board.player[f.f].position].price << "?" << endl;
		cout << "B - Buy\nP - Pass\n";
		cin >> buy;
	}
	if (buy == 'B') {
		board.properties[board.player[f.f].position].owner = f.f;
		board.player[f.f].money -= board.properties[board.player[f.f].position].price;
		if ((board.player[f.f].position == 12) || (board.player[f.f].position == 28)) {
			board.player[f.f].uti += 1;
		}
		if ((board.player[f.f].position == 5) || (board.player[f.f].position == 15) || (board.player[f.f].position == 25) || (board.player[f.f].position == 35)) {
			board.player[f.f].rr += 1;
		}
	}
}
void Pos_0s(Start_return &f, struct board &board) {
	if (board.properties[board.player[f.f].position].owner != f.f) {
		int owner = board.properties[board.player[f.f].position].owner;
		if ((board.player[f.f].position == 5) || (board.player[f.f].position == 15) || (board.player[f.f].position == 25) || (board.player[f.f].position == 35)) {
			switch (board.player[owner].rr) {
			case 1: board.properties[board.player[f.f].position].rent = 25; break;
			case 2: board.properties[board.player[f.f].position].rent = 50; break;
			case 3: board.properties[board.player[f.f].position].rent = 100; break;
			case 4: board.properties[board.player[f.f].position].rent = 200; break;
			}
		}
		else if ((board.player[f.f].position == 12) || (board.player[f.f].position == 28)) {
			cout << "This property is owned by" << board.player[board.properties[board.player[f.f].position].owner].name << endl;
			Roll_return u;
			switch (board.player[owner].uti) {
			case 1: 
				cout << "You must roll the dice and pay 4 times the amount rolled" << endl;
				u = Init_Roll(f);
				board.properties[board.player[f.f].position].rent = u.dice_roll * 4;
				cout << "you paid $" << board.properties[board.player[f.f].position].rent << endl;
				board.player[f.f].money -= board.properties[board.player[f.f].position].rent;
				board.player[board.properties[board.player[f.f].position].owner].money += board.properties[board.player[f.f].position].rent;
				break;
			case 2:
				cout << "You must roll the dice and pay 10 times the amount rolled" << endl;
				u = Init_Roll(f);
				board.properties[board.player[f.f].position].rent = u.dice_roll * 10;
					cout << "you paid $" << board.properties[board.player[f.f].position].rent << endl;
				board.player[f.f].money -= board.properties[board.player[f.f].position].rent;
				board.player[board.properties[board.player[f.f].position].owner].money += board.properties[board.player[f.f].position].rent;
				break;
			}
		}
		else {
			cout << "This property is owned by" << board.player[board.properties[board.player[f.f].position].owner].name << ". Pay $" << board.properties[board.player[f.f].position].rent << endl;
			board.player[f.f].money -= board.properties[board.player[f.f].position].rent;
			board.player[board.properties[board.player[f.f].position].owner].money += board.properties[board.player[f.f].position].rent;
		}
	}
}
void Land(Start_return &f, struct board &board, int dice_roll) {
	if (dice_roll + board.player[f.f].position > 39) {							 //used for when a player is going to pass Boardwalk
		board.player[f.f].position = dice_roll + board.player[f.f].position - 40;//Calculates how far past GO the player will be
		cout << board.player[f.f].name << " landed on " <<						 //Shows what the player landed on
			board.properties[board.player[f.f].position].name << endl;
		board.player[f.f].money += 200;											 //Passing GO grants $200
		if (board.player[f.f].position = 0) {
			board.player[f.f].money += 400;										 //Landing on GO grants $400
		}
		board.player[f.f].laps += 1;
	}
	else {
		cout << board.player[f.f].name << " landed on " <<
			board.properties[dice_roll + board.player[f.f].position].name << endl;
		board.player[f.f].position += dice_roll;
	}
	if ((board.player[f.f].laps < 1) && ((board.player[f.f].position != 2) && (board.player[f.f].position != 4) && (board.player[f.f].position != 7) && (board.player[f.f].position != 10) && (board.player[f.f].position != 17) && (board.player[f.f].position != 20) && (board.player[f.f].position != 22) && (board.player[f.f].position != 30) && (board.player[f.f].position != 33) && (board.player[f.f].position != 36) && (board.player[f.f].position != 38))) {
		cout << "You must go around the board once to be able to purchase properties." << endl;
	}
	else if (board.properties[board.player[f.f].position].owner == -2) { //what to do when landing on other spaces
		Neg_2s(f, board);
	}
	else if (board.properties[board.player[f.f].position].owner == -1) { //what to do when landing on unowned property
		Neg_1s(f, board);
	}
	else if (board.properties[board.player[f.f].position].owner >= 0) { //what to do when landing on owned property
		Pos_0s(f, board);
	}
}
#endif // !SECONDARY

