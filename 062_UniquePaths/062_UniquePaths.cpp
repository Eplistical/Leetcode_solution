/**
 * 62. Unique Paths
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
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
		int uniquePaths(int m, int n) {
			m -= 1;
			n -= 1;

			int rst = 1;
			int a = max(m, n);
			int b = min(m, n);

			int k = m + n;
			while (k > a) {
				rst *= k;
				--k;
			}

			k = b;
			while (k > 0) {
				rst /= k;
				--k;
			}
			return rst;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	return 0;
}
