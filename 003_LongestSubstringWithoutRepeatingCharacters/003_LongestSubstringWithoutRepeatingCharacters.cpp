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
#include <algorithm>
#include <numeric>
#include <string>
#include <map>
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
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string s("umvejcuuk");
	cout << s << "\n";
	cout << S.lengthOfLongestSubstring(s) << "\n"; 
	return 0;
}
