/**
 * 51. N-Queens
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 *
 *   ["..Q.",  // Solution 2
 *    "Q...",
 *    "...Q",
 *    ".Q.."]
 * ]
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
		bool _solve_row(vector<int>& Qs, int row, int n, vector< vector<string> >& rst) {
			bool possible;
			for (int c = 0; c < n; ++c) {
				possible = true;
				for (int r = 0; r < row; ++r) {
					if (Qs[r] == c or abs(Qs[r] - c) == row - r) possible = false;
				}
				if (possible) {
					Qs[row] = c;
					if (row == n - 1) {
						rst.push_back(vector<string>(n, string(n, '.')));
						for (int k = 0; k < n; ++k) {
							rst.back()[k][Qs[k]] = 'Q';
						}
						return true;
					}
					_solve_row(Qs, row + 1, n, rst);
				}
			}
			return false;
		}

		vector<vector<string>> solveNQueens(int n) {
			vector< vector<string> > rst;
			vector<int> Qs(n, -1);

			_solve_row(Qs, 0, n, rst);
			return rst;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	S.solveNQueens(5);
	return 0;
}
