/**
 * 76. Minimum Window Substring
 *
 * Given a string S and a string T,
 * find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 *
 */

#include "showvec.hpp"
#include "showmap.hpp"

// --- include --- // 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

// --- solution part --- //
class Solution {
public:
    string minWindow(string s, string t) {
		if (t.size() == 0) return string("");

		size_t begin, end;
		size_t T = t.size();
		begin = end = 0;
		unordered_map<char, int> dict;

		// check T
		for (char c : t) {
			if (dict.find(c) != dict.end()) ++dict[c];
			else dict[c] = 1;
		}

		// locate first appeared char in t;
		while (begin < s.size()) {
			if (dict.find(s[begin]) != dict.end()) break;
			++begin;
		}
		end = begin;
		if (t.size() == 1) return string(s.begin() + begin, s.begin() + begin + 1);

		// find the first match
		int count = T;
		while (end < s.size()) {
			if (dict.find(s[end]) != dict.end()) {
				// s[end] is in t
				if (dict[s[end]] > 0) --count;
				--dict[s[end]];
			}
			if (count == 0) break;
			++end;
		}
		if (count != 0) return string(""); // cannot find a single match

		// adjust begin
		while (true) {
			if (dict.find(s[begin]) != dict.end()) {
				if (dict[s[begin]] < 0) ++dict[s[begin]];
				else break;
			}
			++begin;
		}

		// rst record
		int rst_begin = begin;
		int rst_end = end;
		int rst_size = rst_end - rst_begin + 1;

		// loop rest of string
		while (end < s.size()) {
			++end;
			if (dict.find(s[end]) != dict.end()) {
				--dict[s[end]];
				while (true) {
					if (dict.find(s[begin]) != dict.end()) {
						if (dict[s[begin]] < 0) ++dict[s[begin]];
						else break;
					}
					++begin;
				}
			}
			if (end - begin + 1 < rst_size) {
				rst_begin = begin;
				rst_end = end;
				rst_size = rst_end - rst_begin + 1;
			}
		}

		return string(s.begin() + rst_begin, s.begin() + rst_begin + rst_size);
    }
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string s = "babcaacabcabbbca";
	string t = "aaabb";
	cout << s << endl;
	cout << t << endl;
	cout << S.minWindow(s, t) << endl;
	return 0;
}
