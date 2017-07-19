/**
 * 53. Maximum Subarray
 *
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
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
		int maxSubArray(vector<int>& nums) {
			if (nums.empty()) return 0;

			int rst = nums[0];
			int maxele = nums[0];

			int numsum = 0;
			for (int i = 0; i < nums.size(); ++i) {
				maxele = max(maxele, nums[i]);
				numsum += nums[i];
				if (numsum < 0) numsum = 0;
				rst = max(rst, numsum);
			}
			if (maxele <= 0) rst = maxele;
			return rst;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	showvec(nums);
	cout << S.maxSubArray(nums) << endl;
	return 0;
}
