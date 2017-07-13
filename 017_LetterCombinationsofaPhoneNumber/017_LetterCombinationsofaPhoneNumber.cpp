/**
 * 17. Letter Combinations of a Phone Number
 *
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
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
		vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string> letterCombinations(string digits) {
			int N = digits.size();
			if (N == 0) return vector<string>();
			int idx;
			vector<vector<string> > DP(N + 1);
			string tmp;
			for (size_t i = 0; i <= N; ++i) {
				if (i == 0) {
					DP[i].push_back(string(""));
				}
				else {
					idx = digits[i - 1] - '0';
					cout << DP[0].size() << endl;
					for (string s : DP[i - 1]) {
						if (idx == 0 or idx == 1) 
							DP[i].push_back(s);
						else 
							for (char c : dict[idx]) {
								tmp = s;
								tmp.push_back(c);
								DP[i].push_back(tmp);
							}
					}
				}

			}
			return DP[N];
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string digits = "20934732";
	showvec(S.letterCombinations(digits));
	cout << S.letterCombinations(digits).size() << endl;
	return 0;
}
