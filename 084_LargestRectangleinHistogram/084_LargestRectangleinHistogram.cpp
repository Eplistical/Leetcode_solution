/**
 * 84. Largest Rectangle in Histogram 
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 * 
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 */

#include "showvec.hpp"
#include "showmap.hpp"

// --- include --- // 
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

// --- solution part --- //
class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            vector<int> st; 
            int rst = 0;
            int h, w;
            heights.push_back(0); 
            for (int j = 0, N = heights.size(); j < N; ++j) {
                while (!st.empty() and heights[j] <= heights[st.back()]) {
                    int idx = st.back();
                    st.pop_back();
                    h = heights[idx];
                    w = st.empty() ? j : j - st.back() - 1;
                    rst = max(rst, w * h);
                }
                st.push_back(j);
            }
            return rst;
        }
};


// --- test part ---//
int main(int argc, char** argv) {
    Solution S;
    vector<int> heights{ 1,3,2,3};
    cout << S.largestRectangleArea(heights) << "\n";
    return 0;
}
