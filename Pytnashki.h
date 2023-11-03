#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

class Pytnashki
{
public:
	Pytnashki(int size);
	pair<int, int> FindPos(int target);
	void Move(int a);
	vector<vector<int>> GetPole();

private:
	vector<vector<int>> pole;
};

