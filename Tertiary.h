#ifndef TERTIARY
#define TERTIARY

#include "Includer.h"
#include "Game.h"
#include "Secondary.h"
void Land(Start_return &f, struct board &board, int dice_roll);

void Comms(Start_return &f) {
	if ((board.player[f.f].position == 2) || (board.player[f.f].position == 17) || (board.player[f.f].position == 33)) { //Community Chest
		int temp_pos = board.player[f.f].position;
		int n = rand() % f.size1;
		cout << board.comm[n].todo << endl;
		if (board.comm[n].card_num == 4) { //get out of jail free card
			board.player[f.f].card = 1;
		}
		else if (board.comm[n].card_num == 5) { //go to jail card
			board.player[f.f].jail = 2;
		}
		else if (board.comm[n].card_num == 6) { // receive $50 from every player card
			board.player[f.f].money += f.num_of_players * 50 + 50;
			for (int i = 0; i < f.num_of_players; i++) {
				board.player[i].money -= 50;
			}
		}
		else if (board.comm[n].card_num == 13) { //hotels and houses
			cout << "You own " << board.player[f.f].hotels << " hotels and " << board.player[f.f].houses << "houses." << endl;
			int hh = ((board.player[f.f].hotels * 115) + (board.player[f.f].houses * 40));
			cout << " Total cost = " << hh << "." << endl;
			board.player[f.f].money -= hh;
			board.properties[20].prize += hh;
		}
		else if ((board.comm[n].position > board.player[f.f].position) && (board.comm[n].position != 40) && (board.comm[n].card_num == 0)) { //going around because of "go to" cards and ATG
			board.player[f.f].laps += 1;
			if (board.comm[n].card_num != 0) {
				board.player[f.f].money += 200;
			}
			else {
				board.player[f.f].money += 600;
			}
		}

		board.player[f.f].money += board.comm[n].money;
		if ((board.comm[n].money < 0) && (board.comm[n].card_num != 6)) {
			board.properties[20].prize -= board.comm[n].money;
		}
		board.player[f.f].position += board.comm[n].spaces;

		if (board.comm[n].position != 40) {
			board.player[f.f].position = board.comm[n].position;
		}
		com_cards temp = board.comm[f.size1]; //next 6 lines are for "shuffling cards" and drawing them.
		board.comm[f.size1] = board.comm[n];
		board.comm[n] = temp;
		f.size1--;
		if (f.size1 == 0) {
			f.size1 = 15;
		}
		if (temp_pos != board.player[f.f].position) {
			Land(f, board, 0);
		}


	}
}
void Chance(Start_return &f) {
	if ((board.player[f.f].position == 7) || (board.player[f.f].position == 22) || (board.player[f.f].position == 36)) {//Chance
		int k = rand() % f.size2;
		int temp_pos = board.player[f.f].position;
		cout << board.chance[k].todo << endl;
		if (board.chance[k].card_num == 7) { //get out of jail free card
			board.player[f.f].card = 1;
		}
		else if (board.chance[k].card_num == 9) { //go to jail card
			board.player[f.f].jail = 2;
		}
		else if (board.chance[k].card_num == 6) { // pay $50 to every player card
			board.player[f.f].money -= f.num_of_players * 50 - 50;
			for (int i = 0; i < f.num_of_players; i++) {
				board.player[i].money += 50;
			}
		}
		else if (board.chance[k].card_num == 10) { // hotels and houses payment
			cout << "You own " << board.player[f.f].hotels << " hotels and " << board.player[f.f].houses << "houses." << endl;
			int hh = ((board.player[f.f].hotels * 100) + (board.player[f.f].houses * 25));
			cout << " Total cost = $" << hh << "." << endl;
			board.player[f.f].money -= hh;
			board.properties[20].prize += hh;
		}
		else if (((board.chance[k].position > board.player[f.f].position) && (board.chance[k].position != 40)) || (board.chance[k].card_num == 0)) { //passing go cards
			board.player[f.f].laps += 1;
			if (board.chance[k].card_num != 0) {
				board.player[f.f].money += 200;
			}
			else {
				board.player[f.f].money += 600;
			}
		}
		board.player[f.f].position += board.chance[k].spaces;
		if (board.chance[k].position != 40) {
			board.player[f.f].position = board.comm[k].position;
		}
		cha_cards temp1 = board.chance[f.size2];
		board.chance[f.size2] = board.chance[k];
		board.chance[k] = temp1;
		f.size2--;
		if (f.size2 == 0) {
			f.size2 = 15;
		}
		if (temp_pos != board.player[f.f].position) {
			Land(f, board, 0);
		}
	}
}

#endif TERTIARY
