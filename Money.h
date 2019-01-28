#ifndef MONEY
#define MONEY

#include "Includer.h"
#include "Game.h"

using namespace std;

void Print_Money(Start_return f) {
	for (int i = 0; i < f.num_of_players; i++) {
		cout << board.player[i].name << ": $" << board.player[i].money << "    ";
	}
	cout << "Free Parking: $:" << board.properties[20].prize << "\n----------------------------------------------\n";
}

#endif // !MONEY
