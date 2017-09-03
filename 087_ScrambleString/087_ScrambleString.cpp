/**
 * 87. Scramble String
 *
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
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
		bool isScramble(string s1, string s2) {
			if (s1 == s2) return true;
			if (s1.size() != s2.size()) return false;

			int count[26] = {0};
			const int N(s1.size());

			for (int i(0); i < N; ++i) {
				count[s1[i] - 'a'] += 1;
				count[s2[i] - 'a'] -= 1;
			}

			for (int c : count) {
				if (c != 0) return false;
			}

			for (int i(1); i < N; ++i) {
				if (isScramble(s1.substr(0, i), s2.substr(0, i)) 
						and isScramble(s1.substr(i), s2.substr(i)))
					return true;

				if (isScramble(s1.substr(0, i), s2.substr(N - i)) 
						and isScramble(s1.substr(i), s2.substr(0, N - i)))
					return true;
			}

			return false;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string s1("abcd");
	string s2("bdac");
	cout << s1 << endl;
	cout << s2 << endl;
	cout << S.isScramble(s1, s2) << endl;
	return 0;
}
