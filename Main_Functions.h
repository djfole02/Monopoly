#ifndef FUNCTIONS
#define FUNCTIONS

#include "Includer.h"
#include "Game.h"
#include "Secondary.h"

using namespace std;

int Roll(Start_return &f, struct board &board) {
	Print_Money(f);
	if (board.player[f.f].jail == 1) {
		cout << "You are in Jail. You must roll doubles." << endl;
		Roll_return jail = Init_Roll(f);
		if (jail.die1 != jail.die2) {
			cout << "You didn't roll doubles, how unfortunate." << endl;
			board.player[f.f].jail_rolls += 1;
			if (board.player[f.f].jail_rolls == 3) {
				cout << "Third time wasn't the charm.. Time to pay $50" << endl;
				board.player[f.f].money -= 50;
				board.properties[20].prize += 50;
				board.player[f.f].jail = 0;
				board.player[f.f].jail_rolls = 0;
			}
		}
		else {
			cout << "You rolled doubles, you may now leave jail on your next turn" << endl;
			board.player[f.f].jail = 0;
			board.player[f.f].jail_rolls = 0;
		}
	}
	else {
		Roll_return r = Init_Roll(f);
		Land(f, board, r.dice_roll);
		while (r.die1 == r.die2) {
			r = Doubles(f, board, r.roll);
			if (r.roll == 3) {
				GTJ(f, board);
				break;
			}
			else {
				Land(f, board, r.dice_roll);
				if (board.player[f.f].jail = 1) {
					break;
				}
			}
		}
	}
	cout << "Press Enter to Continue";
	cin.ignore();
	system("cls");
	Print_Money(f);
	return 0;
} //Roll()

int HH(Start_return &f, struct board &board){
	Print_Money(f);
	struct board hh;
	char mono;
	char prop[2];
	int purple = 0;
	int lightblue = 0;
	int violet = 0;
	int orange = 0;
	int red = 0;
	int yellow = 0;
	int green = 0;
	int darkblue = 0;
	int j = 0;
	for (int i = 0; i < 40; i++) {
		if (board.properties[i].owner == f.f) {
			cout << i + 1 << ": " << board.properties[i].name << endl;
			if (board.properties[i].color == "Purple") {
				purple += 1;
				hh.properties[j] = board.properties[i];
			}
			if (board.properties[i].color == "Light-Blue") {
				lightblue += 1;
				hh.properties[j] = board.properties[i];
			}
			if (board.properties[i].color == "Pink") {
				violet += 1;
				hh.properties[j] = board.properties[i];
			}
			if (board.properties[i].color == "Orange") {
				orange += 1;
				hh.properties[j] = board.properties[i];
			}
			if (board.properties[i].color == "Red") {
				red += 1;
				hh.properties[j] = board.properties[i];
			}
			if (board.properties[i].color == "Yellow") {
				yellow += 1;
				hh.properties[j] = board.properties[i];
			}
			if (board.properties[i].color == "Dark-Green") {
				green += 1;
				hh.properties[j] = board.properties[i];
			}
			if (board.properties[i].color == "Dark-Blue") {
				darkblue += 1;
				hh.properties[j] = board.properties[i];
			}
			j++;
		}
		
	}
	cout << "You own these monopolies: " << endl;
	if ((purple == 2) || (lightblue == 3) || (violet == 3) || (orange == 3) || (red == 3) || (green == 3) || (darkblue == 3)) {
		if (purple == 2) {
			cout << "(V)iolet" << endl;
		}
		if (lightblue == 3) {
			cout << "(L)ight Blue" << endl;
		}
		if (violet == 3) {
			cout << "(P)ink" << endl;
		}
		if (orange == 3) {
			cout << "(O)range" << endl;
		}
		if (red == 3) {
			cout << "(R)ed" << endl;
		}
		if (yellow == 3) {
			cout << "(Y)ellow" << endl;
		}
		if (green == 3) {
			cout << "(G)reen" << endl;
		}
		if (darkblue == 3) {
			cout << "(D)ark Blue" << endl;
		}
		cout << "\nWhich monopoly do you want to access?" << endl;
			cin >> mono;

		switch (mono) {
		case 'V': 
			cout << "1. Mediterranean Avenue" << endl;
			cout << "2. Baltic Avenue" << endl;
			cin >> prop;
		case 'L':
			cout << "1. Oriental Avenue" << endl;
			cout << "2. Vermont Avenue" << endl;
			cout << "3. Connecticut Avenue" << endl;
			cin >> prop;
		case 'P':
			cout << "1. St. Charles Place" << endl;
			cout << "2. States Avenue" << endl;
			cout << "3. Virginia Avenue" << endl;
			cin >> prop;
		case 'O':
			cout << "1. St. James Place" << endl;
			cout << "2. Tennessee Avenue" << endl;
			cout << "3. New York Avenue" << endl;
			cin >> prop;
		case 'R':
			cout << "1. Kentucky Avenue" << endl;
			cout << "2. Indiana Avenue" << endl;
			cout << "3. Illinois Avenue" << endl;
			cin >> prop;
		case 'Y':
			cout << "1. Atlantic Avenue" << endl;
			cout << "2. Ventnor Avenue" << endl;
			cout << "3. Marvin Gardens" << endl;
			cin >> prop;
		case 'G':
			cout << "1. Pacific Avenue" << endl;
			cout << "2. North Carolina Avenue" << endl;
			cout << "3. Pennsylvania Avenue" << endl;
			cin >> prop;
		case 'D':
			cout << "1. Park Place" << endl;
			cout << "2. Boardwalk" << endl;
			cin >> prop;
		}
	}
	else {
		cout << "0 properties." << endl;
	}	
	cout << "Press Enter to Continue";
	cin.ignore();
	cin.ignore();
	system("cls");
	Print_Money(f);
	return 0;
}

//int Mortgage(Start_return &f, struct board &board) {
//	Print_Money(f);
//	struct board mort;
//	int choice;
//	int j = 0;
//	for (int i = 0; i < 40; i++) {
//		if (board.properties[i].owner == f.f) {
//			mort.properties[j] = board.properties[i];
//			cout << j + 1 << ": " << mort.properties[j].name << endl;
//			j++;
//		}
//	}
//	cout << "Which property would you like to mortgage/unmortgage?" << endl;
//	cin >> choice;
//	while ((choice > j + 1) || (choice < 0)) {
//		cout << "Invalid, please choose again." << endl;
//		cin >> choice;
//	}
//
//}
#endif // !FUNCTIONS