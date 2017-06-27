/* 001_TwoSum
 *
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * 	  Because nums[0] + nums[1] = 2 + 7 = 9,
 * 	  return [0, 1].
 */

#include "showvec.hpp"

// --- include --- // 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// --- solution part --- //
class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> indx(nums.size(), 0);
			iota(indx.begin(), indx.end(), 0);
			sort(indx.begin(), indx.end(), [&nums](int i1, int i2){ return nums.at(i1) < nums.at(i2); });

			int first = 0;
			int second = nums.size() - 1;
			int nowsum = 0;
			while (first < second){
				nowsum = nums.at(indx.at(first)) + nums.at(indx.at(second));
				if (nowsum == target)
					return vector<int>{indx.at(first), indx.at(second)};
				else if (nowsum > target)
					second--;
				else 
					first++;
			}
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<int> nums{3, 2, 4};
	cout << "nums:";
	showvec(nums);
	int target = 6;
	cout << "target: " << target << "\n";
	auto rst = S.twoSum(nums, target);
	showvec(rst);
	return 0;
}
