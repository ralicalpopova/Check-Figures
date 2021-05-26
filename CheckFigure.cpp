#include "CheckFigure.h"

// Check for the figure in depth, search for every node part of the figure
void CheckFigures::goDeep(const vector< vector <int>> &matrix, vector< vector <bool>> &checked, int row, int col, short int ComesFrom)
{
	//Check if we are in the matrix
	if (row < matrix.size() && col < matrix[0].size() && row > -1 && col > -1)
		{
		//This node is already checked so we don't care, it is or it will be handled by checkMatrix
			if (checked[row][col] == 1)
			{
				return;
			}
			checked[row][col] = 1;
			if (matrix[row][col])
			{
				//Check where the previous node is coming from
				switch (ComesFrom) {
				case 1: // Left
					goDeep(matrix, checked, row - 1, col, 3);
					goDeep(matrix, checked, row + 1, col, 2);
					goDeep(matrix, checked, row, col + 1, 1);
					break;
				case 2: // Top
					goDeep(matrix, checked, row + 1, col, 2);
					goDeep(matrix, checked, row, col + 1, 1);
					goDeep(matrix, checked, row, col - 1, 4);
					break;
				case 3: // Bottom
					goDeep(matrix, checked, row - 1, col, 3);
					goDeep(matrix, checked, row, col + 1, 1);
					goDeep(matrix, checked, row, col - 1, 4);
					break;
				case 4: // Right
					goDeep(matrix, checked, row - 1, col, 3);
					goDeep(matrix, checked, row + 1, col, 2);
					goDeep(matrix, checked, row, col + 1, 1);
					break;
				default:
					return;
				}
			}
			else
			{
				return;
			}
		}
	else
	{
		return;
	}
}

void CheckFigures::checkMatrix(const vector< vector <int>> &matrix, vector< vector <bool>> &checked, int row, int col)
{
	//Check if we are in the matrix
	if (row < ROW_MAX && col < COL_MAX && row > -1 && col > -1)
		{
			//If the node is already checked we have to check if it comes from goDeep or checkMatrix
			if (checked[row][col] == 1)
			{
				//Check if row + 1 is in matrix, otherwise error will follow
				if (row + 1 < ROW_MAX)
				{
					//if comming from goDeep we have to check it
					//if comming from checkMatrix we already checked around
					if (!checked[row + 1][col])
					{
						checkMatrix(matrix, checked, row + 1, col);
					}
				}
				//Check if row + 1 is in matrix, otherwise error will follow
				if (col + 1 < COL_MAX)
				{
					//if comming from goDeep we have to check it
					//if comming from checkMatrix we already checked around
					if (!checked[row][col + 1])
					{
						checkMatrix(matrix, checked, row, col + 1);
					}
				}				
			}
			else
			{
				//If node is not checked, check it
				checked[row][col] = 1;
				if (matrix[row][col])
				{
					//If there is a figure in the node, go deep to check the whole figure
					goDeep(matrix, checked, row + 1, col, 2);
					goDeep(matrix, checked, row, col + 1, 1);
					goDeep(matrix, checked, row - 1, col, 3);
					figures++;

					//Check next neerest nodes
					checkMatrix(matrix, checked, row + 2, col);
					checkMatrix(matrix, checked, row, col + 2);
					checkMatrix(matrix, checked, row + 1, col + 1);
				}
				else
				{
					//If there is no figure here check next nodes
					checkMatrix(matrix, checked, row + 1, col);
					checkMatrix(matrix, checked, row, col + 1);
				}
			}
		}
	else
	{
		return;
	}
}

void CheckFigures::check(const vector<vector<int>> matrix)
{
	if (!matrix.empty())
	{
		vector<vector<bool>> checked(matrix.size(), std::vector<bool>(matrix[0].size(), 0));
		figures = 0;
		ROW_MAX = matrix.size();
		COL_MAX = matrix[0].size();
		checkMatrix(matrix,checked, 0, 0);
		printf("The matrix has %d figures!\n", figures);
	}
	else
	{
		printf("The matrix has no figures!\n");
	}
};
