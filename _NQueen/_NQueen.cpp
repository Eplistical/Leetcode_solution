/**
 * N Queen problem
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
		void _NQueen(vector<int> now, int next) {
			bool possible;
			vector<int> tmp;

			if (next == now.size()) {
				showvec(now);
				return;
			}

			for (int i = 1; i <= now.size(); ++i) {
				possible = true;
				for (int j = 0; j < next; ++j) {
					if (i == now[j] or 
						i - now[j] == next - j or
						now[j] - i == next - j) 
					{
						possible = false;
						break;
					}
				}
				if (possible) {
					tmp = now;
					tmp[next] = i;
					_NQueen(tmp, next + 1);
				}
			}
		}

		void NQueen(int N) {
			vector<int> rst(N, 0);
			int next = 0;
			_NQueen(rst, next);
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	int N = 8;
	S.NQueen(N);
	return 0;
}
