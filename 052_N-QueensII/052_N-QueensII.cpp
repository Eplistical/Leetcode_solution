/**
 * 52. N-Queens II
 *
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of distinct solutions.
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
		int rst;

		bool _solve_row(vector<int>& Qs, int row, int n) {
			bool possible;
			for (int c = 0; c < n; ++c) {
				possible = true;
				for (int r = 0; r < row; ++r) {
					if (Qs[r] == c or abs(Qs[r] - c) == row - r) possible = false;
				}
				if (possible) {
					Qs[row] = c;
					if (row == n - 1) {
						++rst;
						return true;
					}
					_solve_row(Qs, row + 1, n);
				}
			}
			return false;
		}

		int totalNQueens(int n) {
			vector<int> Qs(n, -1);

			_solve_row(Qs, 0, n);
			return rst;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	cout << S.totalNQueens(4) << endl;
	return 0;
}
