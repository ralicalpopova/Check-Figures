#pragma once
#include <iostream>
#include <vector>

using namespace std;

class CheckFigures
{
	int figures = 0;
	int ROW_MAX = 0;
	int COL_MAX = 0;

	void goDeep(const vector< vector <int>> &matrix, vector< vector <bool>> &checked, int row, int col, short int ComesFrom);

	void checkMatrix(const vector< vector <int>> &matrix, vector< vector <bool>> &checked, int row, int col);

public:
	void check(const vector<vector<int>> matrix);
};



