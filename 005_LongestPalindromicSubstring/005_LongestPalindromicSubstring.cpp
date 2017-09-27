/* 5. Longest Palindromic Substring
 *
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example:
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
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
        string longestPalindrome(string s) {
            const int N(s.size());
            if (N <= 1) {
                return s;
            }

            vector< vector<bool> > dp(N + 1, vector<bool>(N + 1, false));
            int maxstart(0), maxlen(1);

            for (int end(0); end < N + 1; ++end) {
                dp[end][end] = true;
                for (int start(0); start < end; ++start) {  
                    dp[end][start] = ( (dp[end - 1][start + 1] or start == end - 1) 
                                            and s[start] == s[end]);
                    if (dp[end][start] and end - start + 1 > maxlen) {
                        maxstart = start;
                        maxlen = end - start + 1;
                    }
                }
            }

            return s.substr(maxstart, maxlen);
        }

        string longestPalindrome2(string s) {
            // O(1) space
            const int N(s.size());
            if (N <= 1) {
                return s;
            }

            int maxstart(0), maxlen(1);

            for (int end(1); end < N + 1; ++end) {
                int k(1);
                while (k <= end) {
                    if (s[end - k] == s[end + k]) {
                        if (1 + k * 2 > maxlen) {
                            maxlen = 1 + k * 2;
                            maxstart = end - k;
                        }
                        ++k;
                    }
                    else {
                        break;
                    }
                }

                k = 0;
                while (k < end) {
                    if (s[end - 1 - k] == s[end + k]) {
                        if (2 + k * 2 > maxlen) {
                            maxlen = 2 + k * 2;
                            maxstart = end - k - 1;
                        }
                        ++k;
                    }
                    else {
                        break;
                    }
                }
            }

            return s.substr(maxstart, maxlen);
        }

};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
    string s("cbbd");
    cout << S.longestPalindrome2(s) << endl;;
	return 0;
}
