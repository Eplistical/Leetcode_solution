/**
 * 32. Longest Valid Parentheses
 *
 * Given a string containing just the characters '(' and ')', 
 * find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", 
 * where the longest valid parentheses substring is "()()", which has length = 4.
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
		int longestValidParentheses(string s) {
			int rst = 0;
			vector<int> dp(s.size() + 1, 0);

			dp[0] = 0;
			for (int i = 1; i <= s.size(); ++i) {
				if (s[i - 1] == ')' and i >= 2) {
					if (s[i - 2] == '(') {
						dp[i] = dp[i - 2] + 2;
					}
					else if (s[i - dp[i - 1] - 2] == '(') {
						dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
					}
					rst = max(rst, dp[i]);
				}
			}
			return rst;
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string s = "()(((())))";
	cout << s << endl;
	cout << S.longestValidParentheses(s) << endl;
	return 0;
}
