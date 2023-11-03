#include "Pytnashki.h"

/**
* @brief ��������� ����������� �����.
*
* ���� ����� ���������� ����� �� ������� ����, ���� ��� ���������.
*
* @param a �����, ������� ����� �����������.
*
*
* @details ����� ��������� ��������� ���� :
* -������� ������� ��������� ������ ������.
* -������� ������� ��������� �����, ������� ����� �����������(����� a).
* -���������, ����� �� ����������� ����� a �� ������ ������, ����������� �� �������� ����.
* -���� ����������� ���������, ��� �����������.
* -����� ����� ������� ����������� ��������� �������� ���� �� �����.
*
* ���� ����� a �� ���������� �� ������� ���� ��� ����������� ����������, ����� ������� ��������������� ���������.
*/
void Pytnashki::Move(int a) {
	pair<int, int> poszero = FindPos(0);
	pair<int, int> postarget = FindPos(a);
	if (a >= 16) {
		cout << "���� ������ �����.";
		cout << endl;
		return;
	}
	int x1 = poszero.first;
	int y1 = poszero.second;
	int x2 = postarget.first;
	int y2 = postarget.second;
	if ((abs(poszero.first - postarget.first) == 1 && abs(poszero.second - postarget.second) == 1) || (abs(poszero.first - postarget.first) > 1 || abs(poszero.second - postarget.second) > 1)) {
		cout << "�� �� ������ ������� ��� �����.";
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
* @brief �����, ������� ���� ������� ����������� �����.
*
* @param target ����� ������� �������� ����� �����.
*
* @return ���������� ������� ����� � ������� (row, column).
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
* @brief �����, ������� ���������� ������� ������� ����, ����� ��� ����, ����� �������� ��� � �����, ������� ����������� ��� ����������� ����.
*/
vector<vector<int>> Pytnashki::GetPole() {
	return pole;
}


/**
* @brief �����������, ��������� ������� ����.

* @param size ������ �������� ����.

* @details ������� ������� ����, � ��������� ������� �� ���� �������������� �����.
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