/**
 *  41. First Missing Positive
 *
 *  Given an unsorted integer array, find the first missing positive integer.
 *
 *  For example,
 *  Given [1,2,0] return 3,
 *  and [3,4,-1,1] return 2.
 *
 *  Your algorithm should run in O(n) time and uses constant space.
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
		int firstMissingPositive(vector<int>& nums) {
			int i = 0, N = nums.size();
			while(i < N){
				if (nums[i] >= 1 and nums[i] <= N and nums[nums[i] - 1] != nums[i]) {
					swap(nums[i], nums[nums[i] - 1]);
					--i;
				} 
				++i;
			}

			for (i = 0; i < N; ++i) {
				if (nums[i] != i + 1) return i + 1;
			}
			return nums.size() + 1;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<int> nums {1, 1};
	showvec(nums);
	cout << S.firstMissingPositive(nums) << endl;
	return 0;
}
