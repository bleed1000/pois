#include "Pytnashki.h"

/**
* @brief Выполняет перемещение числа.
*
* Этот метод перемещает число на игровом поле, если это допустимо.
*
* @param a Число, которое нужно переместить.
*
*
* @details Метод выполняет следующие шаги :
* -Находит текущее положение пустой ячейки.
* -Находит текущее положение числа, которое нужно переместить(число a).
* -Проверяет, можно ли переместить число a на пустую ячейку, основываясь на правилах игры.
* -Если перемещение разрешено, оно выполняется.
* -Затем метод выводит обновленное состояние игрового поля на экран.
*
* Если число a не существует на игровом поле или перемещение невозможно, метод выводит соответствующее сообщение.
*/
void Pytnashki::Move(int a) {
	pair<int, int> poszero = FindPos(0);
	pair<int, int> postarget = FindPos(a);
	if (a >= 16) {
		cout << "Нету такого числа.";
		cout << endl;
		return;
	}
	int x1 = poszero.first;
	int y1 = poszero.second;
	int x2 = postarget.first;
	int y2 = postarget.second;
	if ((abs(poszero.first - postarget.first) == 1 && abs(poszero.second - postarget.second) == 1) || (abs(poszero.first - postarget.first) > 1 || abs(poszero.second - postarget.second) > 1)) {
		cout << "Вы не можете двигать это число.";
		cout << endl;
		return;
	}
	else swap(pole[x1][y1], pole[x2][y2]);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			if (pole[i][j] < 10) cout << "0";
			cout << pole[i][j] << " ";
		}
		cout << endl;
	}
}

/**
* @brief Метод, который ищет позицию переданного числа.
*
* @param target число позицию которого нужно найти.
*
* @return возвращает позицию числа в формате (row, column).
*/
pair<int, int> Pytnashki::FindPos(int target) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			if (pole[i][j] == target) return make_pair(i, j);
		}
	}
	return make_pair(-1, -1);
}

/**
* @brief Метод, который возвращает текущее игровое поле, нужен для того, чтобы сравнить его с полем, которое достигается при заверешении игры.
*/
vector<vector<int>> Pytnashki::GetPole() {
	return pole;
}


/**
* @brief Конструктор, создающий игровое поле.

* @param size размер игрового поля.

* @details создает игровое поле, и случайным образом по нему разбрасываются числа.
*/
Pytnashki::Pytnashki(int size) : pole(size, vector<int>(size)) {
	srand(time(NULL));
	vector<int> numbers;
	for (int i = 1; i < 16; i++)
	{
		numbers.push_back(i);
	}
	for (int i = 14; i > 0; --i) {
		int j = rand() % (i + 1);
		swap(numbers[i], numbers[j]);
	}
	numbers.push_back(0);
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			pole[i][j] = numbers[k++];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			if (pole[i][j] < 10) cout << "0";
			cout << pole[i][j] << " ";
		}
		cout << endl;
	}
}