/**
 * 42. Trapping Rain Water
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
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
		int trap(vector<int>& height) {
			int N = height.size();
			if (N == 0) return 0;
			vector<int> dp(N);
			dp[0] = 0;
			int i, j, k, tmp;
			for (i = 1; i < N; ++i) {
				tmp = 0;
				if (height[i] > height[i - 1]) {
					j = height[i - 1] + 1;
					while(j <= height[i]) {
						k = i - 1;
						while(k >= 0) {
							if (height[k] >= j) break;
							else ++tmp;
							--k;
						}
						if (k == -1 and height[0] < j) 
							tmp -= i;
						++j;
					}
					dp[i] = dp[i - 1] + tmp;
				}
				else {
					dp[i] = dp[i - 1];
				}
			}
			return dp[N - 1];
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<int> height {};
	showvec(height);
	cout << S.trap(height) << endl;
	return 0;
}
