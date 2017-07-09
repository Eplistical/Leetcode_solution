/**
 * 33. Search in Rotated Sorted Array
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
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
		int search(vector<int>& nums, int target) {
			if (nums.size() == 0) return -1;

			int begin = 0;
			int end = nums.size() - 1;
			int mid;
			while (abs(begin - end) > 1) {
				if (target == nums[begin]) return begin;
				if (target == nums[end]) return end;

				mid = (begin + end) / 2;
				if (target == nums[mid]) return mid;

				if (nums[end] >= nums[begin]) {
					if (target > nums[mid]) begin = mid;
					else end = mid;
				}
				else {
					if (nums[mid] <= nums[end]) {
						if (target < nums[mid] or target > nums[end]) end = mid;
						else begin = mid;
					}
					else {
						if (target > nums[mid] or target < nums[end]) begin = mid;
						else end = mid;
					}
				}
			}
			if (target == nums[begin]) return begin;
			if (target == nums[end]) return end;
			return -1;
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<int> nums {3,5,1};
	int T = 1;
	showvec(nums);
	cout << T << endl;
	cout << S.search(nums, T) << endl;
	return 0;
}
