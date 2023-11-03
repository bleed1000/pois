#include <iostream>
#include "../StaticLib/Pytnashki.h"

int main() {
	setlocale(LC_ALL, "rus");
	Pytnashki game(4);
	vector<vector<int>> targetpole = { {1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 0} };
	int b;
	while (game.GetPole() != targetpole) {

		cin >> b;
		game.Move(b);
	}
	cout << "Win.";
}
