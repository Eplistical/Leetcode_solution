/**
 * 7. Reverse Integer
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * click to show spoilers.
 *
 * Note:
 * The input is assumed to be a 32-bit signed integer. 
 * Your function should return 0 when the reversed integer overflows.
 *
 */

#include "showvec.hpp"
#include "showmap.hpp"

// --- include --- // 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <string>
using namespace std;

// --- solution part --- //
class Solution {
	public:
		int reverse(int x) {
			int sign = (x>=0)?1:-1;
			x = abs(x);
			int rst = 0;
			int tmp = 0;
			int r;
			while (x > 0) {
				r = x % 10;
				x = x / 10;
				if (rst > (numeric_limits<int>::max() - r) / 10.0)
					return 0;
				rst = rst * 10 + r;
			}
			return rst * sign;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	int x = atoi(argv[1]);
	cout << x << endl;
	cout << S.reverse(x) << endl;
	return 0;
}
