/**
 * 97. Interleaving String
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
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
		bool isInterleave(string s1, string s2, string s3) {
			const int N1(s1.size()), N2(s2.size()), N3(s3.size());
			if (N1 + N2 != N3) return 0;
			if (N1 == 0) return (s2 == s3);
			if (N2 == 0) return (s1 == s3);

			vector< vector<bool> > dp(N1 + 1, vector<bool> (N2 + 1, false));

			dp[0][0] = true;
			for (int k(1); k <= N1; ++k) {
				dp[k][0] = dp[k - 1][0] and s1[k - 1] == s3[k - 1];
			}
			for (int k(1); k <= N2; ++k) {
				dp[0][k] = dp[0][k - 1] and s2[k - 1] == s3[k - 1];
			}

			for (int i1(1); i1 <= N1; ++i1) {
				for (int i2(1); i2 <= N2; ++i2) {
					dp[i1][i2] = (dp[i1][i2 - 1] and s2[i2 - 1] == s3[i1 + i2 - 1])
									or (dp[i1 - 1][i2] and s1[i1 - 1] == s3[i1 + i2 - 1]);
				}
			}

			return dp[N1][N2];
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string s1("a");
	string s2("b");
	string s3("ab");
	cout << S.isInterleave(s1, s2, s3) << endl;
	return 0;
}
