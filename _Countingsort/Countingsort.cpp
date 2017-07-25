/**
 * Counting sort algorithm
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
        void CountingSort(vector<int>& nums) {
            // nums must be in range 0 -> N - 1
            int N = 100;
            vector<int> count(N, 0);
            vector<int> tmp(N, 0);

            for (int k : nums) {
                ++count[k];
            }

            int nowpos = 0;
            int pos = 0;
            while (pos < N) {
                if (count[pos] > 0) {
                    nums[nowpos] = pos;
                    --count[pos];
                    ++nowpos;
                }
                else {
                    ++pos;
                }
            }
        }
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
    vector<int> nums{ 1, 4, 1, 2, 7, 5, 2, 29, 90, 27, 29};
    showvec(nums);
    S.CountingSort(nums);
    showvec(nums);
	return 0;
}
