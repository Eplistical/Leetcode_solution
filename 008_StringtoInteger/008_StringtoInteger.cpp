/**
 * 8. String to Integer (atoi)
 *
 * Implement atoi to convert a string to an integer.
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
        int myAtoi(string str) {
            int sign(1);
            long rst(0);
            int i(0);
            while(str[i] == ' ') {
                ++i;
            }
            str = str.substr(i);

            if (str[0] == '+') {
                sign = 1;
                str = str.substr(1);
            }
            else if (str[0] == '-') {
                sign = -1;
                str = str.substr(1);
            }

            i = 0;
            while(str[i] == '0') {
                ++i;
            }
            str = str.substr(i);

            for (i = 0; i < str.size(); ++i) {
                if (str[i] >= '0' and str[i] <= '9') {
                    rst = rst * 10 + str[i] - '0';
                }
                else {
                    break;
                }
                if (rst >= numeric_limits<int>::max() and sign == 1) return numeric_limits<int>::max();
                if (rst > numeric_limits<int>::max() and sign == -1) return numeric_limits<int>::min();
            }
            return rst * sign;
        }
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
    string s("  -0012a42");
    cout << s << endl;
    cout << S.myAtoi(s) << endl;
	return 0;
}
