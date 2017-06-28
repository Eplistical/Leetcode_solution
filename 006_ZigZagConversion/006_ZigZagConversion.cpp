/** 
 * 6. ZigZag Conversion
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
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
#include <cstdlib>
using namespace std;

// --- solution part --- //
class Solution {
	public:
		string convert(string s, int numRows) {
			string rst;
			int step1, step2;
			int stepflag;
			int indx;
			if (numRows == 1) return s;
			for (int r = 0; r < numRows; ++r) {
				indx = r;
				stepflag = 1;
				if (r == 0 or r == numRows - 1) {
					step1 = step2 = 2 * (numRows - 1);
				}
				else {
					step1 = 2 * (numRows - r - 1);
					step2 = 2 * r;
				}
				while (indx < s.size()) {
					rst += s[indx];
					if (stepflag == 1) {
						indx += step1;
						stepflag = 2;
					}
					else if (stepflag == 2) {
						indx += step2;
						stepflag = 1;
					}
				}
			}
			return rst;
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string s(argv[1]);
	int numRows = atoi(argv[2]);
	cout << S.convert(s, numRows) << "\n";
	return 0;
}
