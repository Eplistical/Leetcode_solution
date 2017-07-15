/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 *
 */

#include "showvec.hpp"
#include "showmap.hpp"

// --- include --- // 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

// --- solution part --- //
class Solution {
	public:
		bool valid(const vector<string>& board, int col, int row, int num) {
			int sqrow = row / 3;
			int sqcol = col / 3;

			for (int i = 0; i < 9; ++i)
				if (board[i][row] - '0' == num or board[col][i] - '0' == num) return false;

			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j) 
					if (board[sqcol * 3 + i][sqrow * 3 + j] - '0' == num) return false;

			return true;
		}

		bool _solve(vector<string>& board, int col, int row) {
			int num;
			int nextrow = (row + 1) % 9;
			int nextcol = col + (row + 1) / 9;

			if (board[col][row] != '.') {
				return (col == 8 and row == 8) ? true : _solve(board, nextcol, nextrow);
			}
			else {
				for (num = 1; num <= 9; ++num) {
					if (valid(board, col, row, num)) {
						board[col][row] = num + '0';
						if (row == 8 and col == 8) {
							return true;
						}
						else {
							if (_solve(board, nextcol, nextrow)) {
								return true;
							}
							else {
								board[col][row] = '.';
							}
						}
					}
				}
				return false;
			}
		}

		void solveSudoku(vector<string>& board) {
			_solve(board, 0, 0);
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	return 0;
}
