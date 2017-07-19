/**
 * 45. Jump Game II
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 *
 * Note:
 * You can assume that you can always reach the last index.
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
		int jump_DP(vector<int>& nums) { // DP
			if (nums.empty()) return 0;
			const int N = nums.size();
			vector<int> dp(N, 0);
			int idx = 0;

			for (idx = 0; idx < N; ++idx) {
				dp[idx] = idx;
				for (int i = 0; i < idx; ++i) {
					if (nums[i] >= idx - i) {
						dp[idx] = min(dp[idx], dp[i] + 1);
					}
				}
			}
			showvec(dp);
			return dp[N - 1];
		}

		int jump_improvedDP(vector<int>& nums) { // improved DP
			if (nums.empty()) return 0;
			const int N = nums.size();
			vector<int> dp(N, 0);
			int idx = 0;
			int minidx, tmp;

			while (idx < N) {
				dp[idx] = idx;
				minidx = 0;
				for (int i = idx - 1; i >= 0; --i) {
					if (nums[i] >= idx - i) {
						if (dp[idx] > dp[i] + 1) {
							dp[idx] = dp[i] + 1;
							minidx = i;
						}
					}
				}
				++idx;
				while (idx - minidx <= nums[minidx] and idx < N) {
					dp[idx] = dp[minidx] + 1;
					++idx;
				}
			}
			//showvec(dp);
			return dp[N - 1];
		}

		int jump(vector<int>& nums) { // linear
			if (nums.size() <= 1) return 0;
			int N = nums.size();
			int rst = 0;
			int dest = 0, nextdest = 0;
			int idx = 0;
			int tmp = N - 1;
			while (idx < N) {
				nextdest = max(nextdest, idx + nums[idx]);
				if (idx == dest) {
					++rst;
					dest = nextdest;
					if (dest >= tmp) return rst;
				}
				++idx;
			}
			return rst;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<int> nums {1,2,0,3,4,0,0,2};
	showvec(nums);
	cout << S.jump(nums) << endl;
	return 0;
}
