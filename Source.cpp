#include "Game.h"
#include "Start.h"
#include "Read.h"
#include "Main_Functions.h"

int main() {
	Read();
	Start_return f = Start();
	char choice;
	while (1) {
		system("cls");
		Print_Money(f);
		cout << "Okay " << board.player[f.f].name << " it's your turn.";
		if (board.player[f.f].jail == 1) {
			cout << "\nChoose from the following actions:\n   - (R)oll\n   - (T)rade\n" << endl;
			cin >> choice;
		}
		else {
			cout << "\nChoose from the following actions:\n   - (R)oll\n   - (M)anage\n   - (T)rade\n";
			cin >> choice;
		}

		while (((choice != 'R') && (choice != 'B') && (choice != 'M') && (choice != 'T')) && ((board.player[f.f].jail != 1))) {
			cout << "Invalid, please choose again.\n  ";
			cout << board.player[f.f].name << "'s Turn.\n";
			cout << "Choose from the following actions:\n   - (R)oll\n   - (M)anage\n   - (T)rade\n";
				cin >> choice;
		}
		switch (choice) {
		case 'R':
			system("cls");
			Roll(f, board);
			break;
		case 'M':
			system("cls");
			HH(f, board);
			break;
		}
		f.f += 1;						//Used to go to next player												
		if (f.f == f.num_of_players) {
			f.f = 0;
		}
	}
	system("pause");
	return 0;
}