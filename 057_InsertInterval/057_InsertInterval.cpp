/**
 * 57. Insert Interval
 *
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
/**
 * Definition for an interval.
 */
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
	public:
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			vector<Interval> rst;
			int a = newInterval.start, b = newInterval.end;
			bool aflag = false, bflag = false, inserted = false;
			if (intervals.empty()) {
				rst.push_back(Interval(a,b));
				return rst;
			}
			if (b < intervals[0].start) {
				rst.push_back(Interval(a,b));
				inserted = true;
			}
			for (auto& it : intervals) {
				if (it.end < newInterval.start or it.start > newInterval.end) {
					if (it.end < newInterval.start) aflag = true;
					if (it.start > newInterval.end) bflag = true;
					if (aflag and bflag) {
						rst.push_back(Interval(a,b));
						aflag = bflag = false;
						inserted = true;
					}
					rst.push_back(it);
				}
				else {
					if (it.start <= newInterval.end){
						a = min(it.start, a);
						aflag = true;
					}
					if (it.end >= newInterval.start){
						b = max(it.end, b);
						bflag = true;
					}
				} 
			}
			if (not inserted) {
				rst.push_back(Interval(a,b));
				inserted = true;
			}
			return rst;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<Interval> intervals
	{
		Interval(1,5),
		/*
		Interval(3,5),
		Interval(6,7),
		Interval(8,10),
		Interval(12,16),
		*/
	};
	Interval newInterval(2,3);

	for (auto& it : intervals) {
		cout << '[' << it.start << ", " << it.end << "], ";
	}
	cout << "\n";

	cout << '[' << newInterval.start << ", " << newInterval.end << "], ";
	cout << "\n";


	auto rst = S.insert(intervals, newInterval);
	cout << "\n";
	for (auto& it : rst) {
		cout << '[' << it.start << ", " << it.end << "], ";
	}
	cout << "\n";
	

	return 0;
}
