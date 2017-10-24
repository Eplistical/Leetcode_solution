/**
 * 74. Search a 2D Matrix
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
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
		bool bisearch(const vector<int>& v, int left, int right, int target) {
			if (right - left <= 1) {
				return (v[left] == target or v[right] == target);
			}

			const int mid((left + right) / 2);
			if (v[mid] == target) {
				return true;
			}
			else if (v[mid] < target) {
				return bisearch(v, mid, right, target);
			}
			else {
				return bisearch(v, left, mid, target);
			}
		}

		int bisearch_row(const vector< vector<int> >& m, int left, int right, int target) {
			if (right - left <= 1) {
				if (m[left][0] <= target and m[right][0] > target) {
					return left;
				}
				else {
					return right;
				}
			}

			const int mid((left + right) / 2);
			if (m[mid][0] == target) {
				return mid;
			}
			else if (m[mid][0] < target) {
				return bisearch_row(m, mid, right, target);
			}
			else {
				return bisearch_row(m, left, mid, target);
			}
		}


		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			if (matrix.empty()) 
				return false;
			else if (matrix[0].empty()) 
				return false;

			int row(bisearch_row(matrix, 0, matrix.size() - 1, target));
			return bisearch(matrix[row], 0, matrix[row].size() - 1, target);
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector< vector<int> > m
	{
		vector<int>{1,3,5,7},
		vector<int>{10,11,16,20},
		vector<int>{23,30,34,50}
	};
	cout << S.searchMatrix(m, 25) << endl;
	return 0;
}
