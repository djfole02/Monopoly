#ifndef GAME
#define GAME

#include "Includer.h"

using namespace std;

struct Roll_return {
	int roll;
	int dice_roll;
	int die1;
	int die2;
};
struct Start_return {
	int f;
	int num_of_players;
	int size1;
	int size2;
};
struct com_cards {
	string todo;
	int card_num;
	int money;
	int spaces;
	int position;
	int hotels;
	int houses;
	int jail;
};

struct cha_cards {
	string todo;
	int card_num;
	int money;
	int spaces;
	int position;
	int hotels;
	int houses;
	int jail;
};

struct properties {
	string name;
	int price;
	int mortgage;
	int position;
	int rent;
	int upgrade[4];
	int p_hotels;
	int p_houses;
	int n_houses;
	string color;
	int owner;
	int prize;
};

struct player {
	string name;
	int money;
	int position;
	int laps;
	int hotels;
	int houses;
	int jail;
	int card;
	int rr;
	int uti;
	int jail_rolls;
	struct owned_properties;
	struct mortgage_properties;
};
struct board {
	struct properties properties[40];
	struct player player[5];
	struct cha_cards chance[16];
	struct com_cards comm[16];
}board;

#endif


