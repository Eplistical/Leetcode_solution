/**
 * 30. Substring with Concatenation of All Words
 *
 * You are given a string, s, and a list of words, words, that are all of the same length. 
 * Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 *
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 *
 */

#include "showvec.hpp"
#include "showmap.hpp"

// --- include --- // 
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <string>
using namespace std;

// --- solution part --- //
class Solution {
	public:
		bool check(string s, vector<string>& words) {
			// check if s is a combination of words (given len(s) = len(words))
			vector<string> w = words;
			if (w.size() == 0) return (s.size() == 0);
			int S = w[0].size();
			unordered_map<string, int> dict;
			string sub;
			for (auto& it : words) {
				if (dict.find(it) != dict.end())
					++dict[it];
				else 
					dict[it] = 0;
			}
			typename unordered_map<string, int>::iterator itr;
			for (size_t i = 0; i < words.size(); ++i) {
				sub = string(s.begin() + i * S, s.begin() + i * S + S);
				itr = dict.find(sub);
				if (itr == dict.end() or itr->second < 0) {
					return false;
				}
				else {
					--itr->second;
				}
			}
			return true;
		}

		vector<int> findSubstring(string s, vector<string>& words) {
			if (words.size() == 0) return vector<int>();
			int N = words.size();
			int S = words[0].size();
			vector<vector<int> > DP(s.size() + 1, vector<int>());
			for (size_t i = N * S; i <= s.size(); ++i) {
				DP[i] = DP[i - 1];
				if (check(string(s.begin() + i - N * S, s.begin() + i), words)) {
					DP[i].push_back(i - N * S);
				}
			}
			return DP[s.size()];
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<string> w {"foo", "bar", "man"};
	string s("barfoothefoobarman");
	cout << s << endl;
	showvec(w);
	showvec(S.findSubstring(s, w));
	return 0;
}
