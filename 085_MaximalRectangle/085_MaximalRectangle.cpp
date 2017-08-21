/**
 * 85. Maximal Rectangle
 * 
 * Given a 2D binary matrix filled with 0's and 1's
 * find the largest rectangle containing only 1's and return its area.
 *
 * For example, given the following matrix:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Return 6.
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
		int maximalRectangle(vector<vector<char>>& matrix) {
			int rst = 0;
			if (matrix.empty()) return rst;

			int Ncol = matrix.size();
			int Nrow = matrix[0].size();
			vector<int> counter(Nrow, 0);

			for (int col = 0; col < Ncol; ++col) {
				for (int row = 0; row < Nrow; ++row) {
					if (matrix[col][row] == '1') {
						++counter[row];
					}
					else {
						counter[row] = 0;
					}
				}	
				for (int row = 0; row < Nrow; ++row) {
					if (counter[row] > 0) {
						showvec(counter);
						int h = 1;
						int w = counter[row];
						while (h + row <= Nrow and counter[h + row - 1] != 0) {
							w = min(w, counter[h + row - 1]);
							cout << h << w << endl;
							rst = max(rst, w * h);
							++h;
						}
					}
				}
			}
			return rst;
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<vector<char>> matrix 
	{
		vector<char> {'1','0','1','0','0'},
		vector<char> {'1','0','1','1','1'},
		vector<char> {'1','1','1','1','1'},
		vector<char> {'1','0','0','1','0'},
	};
	cout << S.maximalRectangle(matrix) << '\n';
	
	return 0;
}
