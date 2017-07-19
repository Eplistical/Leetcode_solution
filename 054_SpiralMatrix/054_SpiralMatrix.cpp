/**
 * 54. Spiral Matrix
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3  ],
 *  [ 4, 5, 6  ],
 *  [ 7, 8, 9  ]
 * ]
 * 
 * You should return [1,2,3,6,9,8,7,4,5].
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
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			vector<int> rst;
			int Nrow = matrix.size();
			if (Nrow == 0) return rst;
			int Ncol = matrix[0].size();
			if (Ncol == 0) return rst;
			vector<int> rowbound {0, Nrow - 1};
			vector<int> colbound {0, Ncol - 1};

			int nowrow = 0, nowcol = 0;
			int rowstep = 0, colstep = 1;

			while(rst.size() < Nrow * Ncol and (rowbound[1] >= rowbound[0] or colbound[1] >= colbound[0])) {
				if (nowrow > rowbound[1]) {
					nowrow = rowbound[1];
					--colbound[1];
					rowstep = 0;
					colstep = -1;
					nowrow += rowstep;
					nowcol += colstep;
				}
				else if (nowrow < rowbound[0]) {
					nowrow = rowbound[0];
					++colbound[0];
					rowstep = 0;
					colstep = 1;
					nowrow += rowstep;
					nowcol += colstep;
				}
				if (nowcol > colbound[1]) {
					nowcol = colbound[1];
					++rowbound[0];
					colstep = 0;
					rowstep = 1;
					nowrow += rowstep;
					nowcol += colstep;
				}
				else if (nowcol < colbound[0]) {
					nowcol = colbound[0];
					--rowbound[1];
					colstep = 0;
					rowstep = -1;
					nowrow += rowstep;
					nowcol += colstep;
				}
				rst.push_back(matrix[nowrow][nowcol]);
				nowrow += rowstep;
				nowcol += colstep;
			}
			return rst;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector< vector<int> > matrix 
	{
		{1},
	};
	for (auto& v : matrix) {
		showvec(v);
	}
	showvec(S.spiralOrder(matrix));
	return 0;
}
