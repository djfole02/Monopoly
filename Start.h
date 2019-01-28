#ifndef START
#define START
#include "Includer.h"
#include <algorithm>
Start_return Start() {
	int num_of_players = 0;
	int size1 = 15;
	int size2 = 15;
	int first = 0;
	cout << "How many players?: ";
	cin >> num_of_players;
	while ((num_of_players <= 1) || (num_of_players > 6)) {
		cout << "Invalid Number of Players, Try Again" << endl;
		cout << "How many players?: ";
		cin >> num_of_players;
	}
	for (int i = 0; i < num_of_players; i++) {
		cout << "Name of Player " << i + 1 << ":  ";
		cin >> board.player[i].name;
		board.player[i].money = 1500;
		board.player[i].position = 0;
		board.player[i].laps = 0;
		board.player[i].hotels = 0;
		board.player[i].houses = 0;
		board.player[i].jail = 0;
		board.player[i].card = 0;
		board.player[i].rr = 0;
		board.player[i].uti = 0;
		board.player[i].jail_rolls = 0;
	}
	system("cls");
	cout << "Alright, let's see who goes first...\n" << endl;
	Sleep(1000);
	system("cls");
	srand(time(NULL));
	first = rand() % num_of_players;
	cout << "Looks like it's " << board.player[first].name << endl;
	Sleep(1000);
	cout << "Let's get this show on the road " << board.player[first].name << "!" << endl;
	Sleep(2000);
	system("cls");
	Start_return result = { first, num_of_players, size1, size2 };
	return result;
}
#endif // !START

