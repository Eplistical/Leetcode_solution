/**
 * 72. Edit Distance
 *
 * Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 * a) Insert a character
 * b) Delete a character
 * c) Replace a character
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
		int minDistance(string word1, string word2) {
			int N1 = word1.size();
			int N2 = word2.size();
			vector< vector<int> > dp(N1 + 1, vector<int> (N2 + 1, 0));

			for (int i = 0; i <= N1; ++i) {
				dp[i][0] = i;
				for (int j = 1; j <= N2; ++j) {
					if (i == 0) {
						dp[0][j] = j;
					} 
					else {
						if (word1[i - 1] == word2[j - 1]) {
							dp[i][j] = dp[i - 1][j - 1];
						}
						else {
							dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
						}
					}
				}
			}
			return dp[N1][N2];
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string word1 = "adsbdaf";
	string word2 = "adsadlsfcf";
	cout << word1 << endl;
	cout << word2 << endl;
	cout << S.minDistance(word1, word2) << "\n";
	return 0;
}
