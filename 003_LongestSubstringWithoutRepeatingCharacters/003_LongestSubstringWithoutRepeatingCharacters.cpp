/* 3. Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 */

#include "showvec.hpp"
#include "showmap.hpp"

// --- include --- // 
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <cstdlib>
#include <cmath>
using namespace std;

// --- solution part --- //
class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			const int LEN = s.size();
			int leftind = 0;
			int rightind = 0;
			int maxlen = 0; 
			map<char, int> indextable;
			char c;
			while (rightind < LEN) {
				c = s[rightind];
				if (indextable.find(c) != indextable.end()) {
					if (indextable.size() > maxlen) maxlen = indextable.size();
					while(leftind <= indextable[c]){
						indextable.erase(s[leftind]);
						++leftind;
					}
				}
				indextable[c] = rightind;
				++rightind;
			}
			if (indextable.size() > maxlen) maxlen = indextable.size();
			return maxlen;
		}

		// use vector as hashtable
		int lengthOfLongestSubstring2(string s) {
			const int LEN = s.size();
			int leftind = 0;
			int maxlen = 0; 
			vector<int> indextable(256, -1);
			char c;
			for (int rightind = 0; rightind < LEN; ++rightind) {
				leftind = max(leftind, indextable[s[rightind]] + 1);
				indextable[s[rightind]] = rightind;
				maxlen = max(maxlen, rightind - leftind + 1);
			}
			return maxlen;
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string s("c");
	cout << s << "\n";
	cout << S.lengthOfLongestSubstring2(s) << "\n"; 
	return 0;
}
