/**
 * 44. Wildcard Matching
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") ? false
 * isMatch("aa","aa") ? true
 * isMatch("aaa","aa") ? false
 * isMatch("aa", "*") ? true
 * isMatch("aa", "a*") ? true
 * isMatch("ab", "?*") ? true
 * isMatch("aab", "c*a*b") ? false
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
		bool compare(char s, char p) {
			return (s == p) or p == '?';
		}

		bool isMatch_recursive(string s, string p) {	// recursively, cannot pass because of time limite exceeded.
			if (p.empty()) {
				return s.empty();
			}
			else if (p[0] == '*') {
				return (!s.empty() and isMatch(s.substr(1), p)) 
					or isMatch(s, p.substr(1));
			}
			else {
				return (!s.empty() and compare(s[0], p[0]) and isMatch(s.substr(1), p.substr(1)));
			}
		}

		bool isMatch_DP(string s, string p) {	// DP
			size_t n = s.size(), m = p.size();
			vector<vector<bool> > DP(n+1, vector<bool>(m+1, false));
			DP[0][0] = true;

			for (int i = 0; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					if (p[j - 1] != '*') {
						DP[i][j] = (i != 0) and compare(s[i-1], p[j-1]) and DP[i-1][j-1];

					}
					else {
						DP[i][j] = ( i != 0 and DP[i-1][j]  )
							or ( DP[i][j-1]  );

					}

				}

			}
			return DP[n][m];
		}

		bool isMatch(string s, string p) {
			//return isMatch_recursive(s, p);
			return isMatch_DP(s, p);
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string s(argv[1]);
	string p(argv[2]);
	cout << s << "\n";
	cout << p << "\n";
	cout << S.isMatch(s, p) << "\n";
	return 0;
}
