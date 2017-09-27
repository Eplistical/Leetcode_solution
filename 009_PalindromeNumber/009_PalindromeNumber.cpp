/** 
 *  9. Palindrome Number
 *
 *  Determine whether an integer is a palindrome. Do this without extra space.
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
        bool isPalindrome(int x) {
            if (x < 0) return false;
            if (x < 10) return true;
            if (x % 10 == 0) return false;

            int rev(0);
            while (x > rev) {
                rev = rev * 10 + x % 10;
                x /= 10;
            }

            return (x == rev or x == rev / 10);
        }
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	return 0;
}
