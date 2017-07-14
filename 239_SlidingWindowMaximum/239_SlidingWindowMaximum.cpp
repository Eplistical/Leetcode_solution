/**
 * 239. Sliding Window Maximum
 *
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 *
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *
 * Window position                Max
 * ---------------               -----
 *  [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 *  Therefore, return the max sliding window as [3,3,5,5,6,7].
 *
 * Note: 
 * You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
 *
 * Follow up:
 * Could you solve it in linear time?
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
		using Pair = pair<int, int>; // (idx, val) pair

		void push(vector<Pair>& H, const Pair& x) {
			H.push_back(x);
			push_heap(H.begin(), H.end(), [](const Pair& left, const Pair& right){ return left.second < right.second; });
		}

		void pop(vector<Pair>& H) {
			pop_heap(H.begin(), H.end(), [](const Pair& left, const Pair& right){ return left.second < right.second;  });
			H.pop_back();
		}

		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			vector<Pair> H; 
			vector<int> rst;
			if (nums.empty()) return rst;
			make_heap(H.begin(), H.end(), [](const Pair& left, const Pair& right){ return left.second < right.second;  });
			int i = 0;
			int maxidx = 0; 
			int N = nums.size();
			while (i < k) {
				push(H, Pair(i, nums[i]));
				++i;
			}

			rst.push_back(H.front().second);
			while (i < N) {
				push(H, Pair(i, nums[i]));
				while (H.front().first < i - k + 1) {
					pop(H);
				}
				rst.push_back(H.front().second);
				++i;
			}
			return rst;
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<int> nums {1, -1, 3, 6, 9, 4};
	int k = 3;
	showvec(S.maxSlidingWindow(nums, k));
	return 0;
}
