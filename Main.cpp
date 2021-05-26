#include "CheckFigure.h"

void test()
{
	CheckFigures obj;
	vector<vector<int>> matrix(5, std::vector<int>(5, 0));
	matrix[0][0] = 1;
	matrix[1][0] = 1;
	matrix[1][2] = 1;
	matrix[1][3] = 1;
	matrix[2][1] = 1;
	matrix[2][3] = 1;
	matrix[3][1] = 1;
	matrix[3][2] = 1;
	matrix[3][3] = 1;
	matrix[4][4] = 1;

	vector<vector<int>> matrix1(8, std::vector<int>(5, 0));
	matrix1[0][0] = 1;
	matrix1[1][0] = 1;
	matrix1[1][3] = 1;
	matrix1[2][3] = 1;
	matrix1[0][4] = 1;
	matrix1[3][1] = 1;
	matrix1[4][1] = 1;
	matrix1[3][4] = 1;
	matrix1[4][4] = 1;
	matrix1[5][3] = 1;
	matrix1[6][3] = 1;
	matrix1[7][0] = 1;
	matrix1[7][2] = 1;
	matrix1[7][4] = 1;

	vector<vector<int>> matrix2(20, std::vector<int>(10, 0));
	matrix2[0][0] = 1;
	matrix2[1][0] = 1;
	matrix2[1][3] = 1;
	matrix2[2][3] = 1;
	matrix2[0][4] = 1;
	matrix2[3][1] = 1;
	matrix2[4][1] = 1;
	matrix2[3][4] = 1;
	matrix2[4][4] = 1;
	matrix2[5][3] = 1;
	matrix2[6][3] = 1;
	matrix2[7][0] = 1;
	matrix2[7][2] = 1;
	matrix2[7][4] = 1;
	matrix2[10][7] = 1;
	matrix2[15][8] = 1;

	obj.check(matrix);
	obj.check(matrix1);
	obj.check(matrix2);
}


int main()
{
	test();
    return 0;
}

