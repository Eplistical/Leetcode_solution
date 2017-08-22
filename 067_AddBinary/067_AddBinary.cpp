/**
 * 67. Add Binary
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
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
		string addBinary(string a, string b) {
			if (a.size() < b.size()) return addBinary(b, a); 
			int na = a.size() - 1;
			int nb = b.size() - 1;
			int extra = 0;
			string rst(a);
			char c;
			while (na >= 0) {
				if (nb >= 0) {
					c = b[nb] + a[na] - '0' + extra;

				}
				else {
					c = a[na] + extra;

				}

				if (c >= '2') {
					c -= 2;
					extra = 1;

				}
				else {
					extra = 0;

				}
				rst[na] = c;
				--na;
				--nb;

			}
			if (extra == 1) {
				rst = string("1") + rst;

			}
			return rst;

		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	string a("0");
	string b("0");
	cout << a << ' ' << b << ' ' << '\n';
	cout << "rst: " <<  S.addBinary(a, b) << '\n';
	return 0;
}
