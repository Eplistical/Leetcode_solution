/**
 * 73. Set Matrix Zeroes
 *
 * Given a m x n matrix, if an element is 0, 
 * set its entire row and column to 0. 
 * Do it in place.
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
		void setZeroes(vector<vector<int>>& matrix) {
			if (matrix.empty()) return;

			const int Nr = matrix.size();
			const int Nc = matrix[0].size();

			vector<int> zeroRs;
			vector<int> zeroCs;

			for (int r = 0; r < Nr; ++r) {
				for (int c = 0; c < Nc; ++c) {
					if (matrix[r][c] == 0) {
						zeroRs.push_back(r);
						zeroCs.push_back(c);
					}
				}
			}

			for (int r : zeroRs) {
				matrix[r].assign(Nc, 0);
			}

			for (int c : zeroCs) {
				for (int r = 0; r < Nr; ++r) {
					matrix[r][c] = 0;
				}
			}
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	return 0;
}
