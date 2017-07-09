/**
 * 10. Regular Expression Matching
 * Implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
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
 * isMatch("aa", "a*") ? true
 * isMatch("aa", ".*") ? true
 * isMatch("ab", ".*") ? true
 * isMatch("aab", "c*a*b") ? true
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
			return (s == p or p == '.');
		}

		bool isMatch_recursive(string s, string p) {	// recursive 
			if (p.empty()) 
				return s.empty();
			else if (p[1] == '*') 
				return (isMatch(s, p.substr(2))) || (!s.empty() && compare(s[0], p[0]) && (isMatch(s.substr(1), p) ));
			else 
				return !s.empty() && compare(s[0], p[0]) && isMatch(s.substr(1), p.substr(1)); 
		}

		bool isMatch_DP(string s, string p) {	// DP
			size_t n = s.size(), m = p.size();
			// DP matrix
			vector<vector<bool> > DP(n + 1, vector<bool>(m + 1, false));
			DP[0][0] = true;

			for (int i = 0; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					if (p[j - 1] != '*') {
						DP[i][j] = i != 0 and DP[i-1][j-1] and compare(s[i-1], p[j-1]);
					}
					else {
						if (i != 0 and compare(s[i-1], p[j-2])) {
							DP[i][j] = DP[i][j-2] or DP[i-1][j] or DP[i-1][j-1];
						}
						else {
							DP[i][j] = DP[i][j-2];
						}
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
	cout << "ans: " << S.isMatch(s, p) << "\n";
	return 0;
}
