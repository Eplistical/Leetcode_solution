/**
 * 66. Plus One
 *
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 *
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
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
		vector<int> plusOne(vector<int>& digits) {
			vector<int> rst(digits);
			if (rst.size() == 1) {
				if (rst[0] == 9) {
					rst =  vector<int> { 1, 0 };
				}
				else {
					rst[0] += 1;
				}
			}
			else {
				if (rst.back() != 9) {
					rst[rst.size() - 1] += 1;
				}
				else {
					rst.pop_back();
					rst = plusOne(rst);
					rst.push_back(0);
				}
			}
			return rst;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<int> digits{ 9,9,9 };
	showvec(digits);
	showvec(S.plusOne(digits));
	return 0;
}
