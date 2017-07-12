/**
 * Searching for Patterns
 *
 * Given a text txt[0..n-1] and a pattern pat[0..m-1], 
 * write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. 
 * You may assume that n > m.
 *
 * Examples:
 *
 * Input:  txt[] = "THIS IS A TEST TEXT"
 *         pat[] = "TEST"
 *         Output: Pattern found at index 10
 *
 *         Input:  txt[] =  "AABAACAADAABAABA"
 *                 pat[] =  "AABA"
 *                 Output: Pattern found at index 0
 *                         Pattern found at index 9
 *                         Pattern found at index 12
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
		vector<int> getlps(string p) {
			// preprocessor
			vector<int> lps(p.size());
			int i, k;
			i = 1;
			while (i < p.size()) {
				k = 0;
				while (k < i) {
					if (p[k] == p[i] and p.substr(0, k + 1) == p.substr(i - k, k + 1)) {
							lps[i] = k + 1;
						}
					++k;
				}
				++i;
			}
			return lps;
		}

		void SearchforPatterns(string s, string p) {
			int NP = p.size();
			int NS = s.size();
			int i, j;
			vector<int> lps = getlps(p);

			i = j = 0;
			while(i < NS) {
				if (s[i] == p[j]) {
					++i;
					++j;
					if (j == NP) {
						cout << "found match: " << i - NP << endl;
						j = lps[j - 1];
					}
				}
				else {
					j = lps[j - 1];
					if (j == 0) ++i;
				}
			}
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string s = "AABAACAADAABAABA";
	string p = "AABA";
	cout << s << endl;
	cout << p << endl;
	S.SearchforPatterns(s, p);
	return 0;
}
