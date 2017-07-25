/**
 *  65. Valid Number
 *
 *  Validate if a given string is numeric.
 *
 *  Some examples:
 *  "0" => true
 *  " 0.1 " => true
 *  "abc" => false
 *  "1 a" => false
 *  "2e10" => true
 *  Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 *
 */

#include "showvec.hpp"
#include "showmap.hpp"

// --- include --- // 
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <string>
using namespace std;

// --- solution part --- //
class Solution {
	public:
		void trim(string& s) {
			int begin = 0, end = s.size() - 1;
			while(s[begin] == ' ' or s[begin] == '\t' or s[begin] == '\n') ++begin;
			while(s[end] == ' ' or s[end] == '\t' or s[end] == '\n') --end;

			s = s.substr(begin, end - begin + 1);
		}

		bool _non_sci(string s) {
			unordered_set<char> validchar { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
			unordered_set<char> validbegin { '.', '+', '-' };
			unordered_set<char> validend { 'L', 'l', 'u', 'U'};
			bool dotflag = false;
			bool digitflag = false;
			// single digit
			if (s.size() == 1) 
				return (validchar.find(s[0]) != validchar.end());
			// first char
			if (validbegin.find(s[0]) == validbegin.end() 
					and validchar.find(s[0]) == validchar.end()) return false;
			if (s[0] == '.') 
				dotflag = true;
			if (validchar.find(s[0]) != validchar.end())
				digitflag = true;
			// rest
			for (int i = 1; i < s.size(); ++i) {
				if (validchar.find(s[i]) == validchar.end() and s[i] != '.') 
					return false;
				if (s[i] == '.') {
					if (dotflag) return false;
					dotflag = true;
				}
				else {
					digitflag = true;
				}
			}
			if (!digitflag) return false;
			return true;
		}

		bool isNumber(string s) {
			trim(s);

			auto found = s.find('e');
			if (found == string::npos) {
				return _non_sci(s);
			}
			else {
				string s1(s.begin(), s.begin() + found);
				string s2(s.begin() + found + 1, s.end());
				return _non_sci(s1) and _non_sci(s2);
			}
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	//string s("1e3");
	//cout << s << endl;
	//cout << S.isNumber(s) << endl;
	cout << S.isNumber(argv[1]) << endl;
	return 0;
}
