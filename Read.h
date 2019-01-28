#ifndef READ
#define READ
#include "Includer.h"
#include "Game.h"
void Read() {
	string line;
	ifstream myFile("Properties.txt");
	ifstream Comm("Community.txt");
	ifstream Chance("Chance.txt");
	int num1, num2, num3, num4, num5, num6, num7;

	for (int i = 0; i < 40; i++) {
		getline(myFile, line);
		board.properties[i].name = line;

		getline(myFile, line);
		num1 = stoi(line, nullptr, 10);
		board.properties[i].position = num1;

		getline(myFile, line);
		num2 = stoi(line, nullptr, 10);
		board.properties[i].price = num2;

		getline(myFile, line);
		num3 = stoi(line, nullptr, 10);
		board.properties[i].rent = num3;

		for (int j = 0; j < 5; j++) {
			getline(myFile, line);
			num5 = stoi(line, nullptr, 10);
			board.properties[i].upgrade[j] = num5;
		}

		getline(myFile, line);
		board.properties[i].color = line;

		getline(myFile, line);
		num4 = stoi(line, nullptr, 10);
		board.properties[i].owner = num4;

		getline(myFile, line);
		num3 = stoi(line, nullptr, 10);
		board.properties[i].n_houses = num3;

		getline(myFile, line);
		num3 = stoi(line, nullptr, 10);
		board.properties[i].p_houses = num3;

		getline(myFile, line);
		num3 = stoi(line, nullptr, 10);
		board.properties[i].p_hotels = num3;
	}
	for (int i = 0; i < 16; i++) {
		getline(Comm, line);
		board.comm[i].todo = line;

		getline(Comm, line);
		num7 = stoi(line, nullptr, 10);
		board.comm[i].card_num = num7;

		getline(Comm, line);
		num1 = stoi(line, nullptr, 10);
		board.comm[i].money = num1;

		getline(Comm, line);
		num2 = stoi(line, nullptr, 10);
		board.comm[i].spaces = num2;

		getline(Comm, line);
		num3 = stoi(line, nullptr, 10);
		board.comm[i].position = num3;

		getline(Comm, line);
		num4 = stoi(line, nullptr, 10);
		board.comm[i].hotels = num4;

		getline(Comm, line);
		num5 = stoi(line, nullptr, 10);
		board.comm[i].houses = num5;

		getline(Comm, line);
		num6 = stoi(line, nullptr, 10);
		board.comm[i].jail = num6;

	}
	for (int i = 0; i < 16; i++) {
		getline(Chance, line);
		board.chance[i].todo = line;

		getline(Chance, line);
		num7 = stoi(line, nullptr, 10);
		board.chance[i].card_num = num7;

		getline(Chance, line);
		num1 = stoi(line, nullptr, 10);
		board.chance[i].money = num1;

		getline(Chance, line);
		num2 = stoi(line, nullptr, 10);
		board.chance[i].spaces = num2;

		getline(Chance, line);
		num3 = stoi(line, nullptr, 10);
		board.chance[i].position = num3;

		getline(Chance, line);
		num4 = stoi(line, nullptr, 10);
		board.chance[i].hotels = num4;

		getline(Chance, line);
		num5 = stoi(line, nullptr, 10);
		board.chance[i].houses = num5;

		getline(Chance, line);
		num6 = stoi(line, nullptr, 10);
		board.chance[i].jail = num6;
	}
	board.properties[20].prize = 500;
}
#endif // !READ

