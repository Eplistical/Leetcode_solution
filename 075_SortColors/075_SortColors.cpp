/**
 * 75. Sort Colors
 *
 * Given an array with n objects colored red, white or blue, 
 * sort them so that objects of the same color are adjacent, 
 * with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent 
 * the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
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
		void sortColors(vector<int>& nums) {
			int lb(0), rb(nums.size() - 1);
			int idx(0);

			while (idx <= rb) {
				if (nums[idx] == 0) {
					swap(nums[idx], nums[lb]);
					++lb;
				}
				else if (nums[idx] == 2) {
					swap(nums[idx], nums[rb]);
					--rb;
					--idx;
				}
				++idx;
			}
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<int> v{0,1,2,1,1,0,2,0,1};
	showvec(v);
	S.sortColors(v);
	showvec(v);
	return 0;
}
