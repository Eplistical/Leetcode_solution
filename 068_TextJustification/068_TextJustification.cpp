/**
 * 68. Text Justification
 *
 * Given an array of words and a length L, 
 * format the text such that each line has exactly L characters and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; 
 * that is, pack as many words as you can in each line.
 * Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. 
 * If the number of spaces on a line do not divide evenly between words, 
 * the empty slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 *
 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 *
 * Note: Each word is guaranteed not to exceed L in length.
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
		string genstr(const vector<string>& words, int beginpos, int endpos, int maxWidth) {
			string rst;

			if (beginpos == endpos) {
				rst = words[beginpos];
				while (rst.size() < maxWidth) rst.push_back(' ');
				return rst;
			}

			int Nnonspace = 0;
			int Nspace = 0;
			int Nword = endpos - beginpos + 1;

			for (int i = beginpos; i <= endpos; ++i) {
				Nnonspace += words[i].size();
			}
			Nspace = maxWidth - Nnonspace;
			int spacelen = Nspace / (Nword - 1);
			int extraspace = Nspace % (Nword - 1); 
			for (int i = beginpos; i < endpos; ++i) {
				rst += words[i];
				for (int j = 0; j < spacelen; ++j) rst.push_back(' ');
				if (i - beginpos < extraspace) rst.push_back(' ');
			}
			rst += words[endpos];
			return rst;
		}

		vector<string> fullJustify(vector<string>& words, int maxWidth) {
			vector<string> rst;
			int pos = 0;
			int beginpos = 0;
			int nowsize = 0;
			while (pos < words.size()) {
				nowsize += words[pos].size();
				if (nowsize < maxWidth) {
					nowsize += 1;
					++pos;
				}
				else if (nowsize == maxWidth) {
					rst.push_back(genstr(words, beginpos, pos, maxWidth));
					++pos;
					beginpos = pos;
					nowsize = 0;
				}
				else {
					rst.push_back(genstr(words, beginpos, pos - 1, maxWidth));
					beginpos = pos;
					nowsize = 0;
				}
			}

			// last line
			if (beginpos < words.size()) {
			string lastline = "";
				for (int i = beginpos; i < words.size(); ++i) {
					lastline += words[i];
					if (lastline.size() < maxWidth) lastline.push_back(' ');
				}
				while (lastline.size() < maxWidth) {
					lastline.push_back(' ');
				}
				rst.push_back(lastline);
			}
			return rst;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	vector<string> str { "a","b","c","d","e" };

	auto rst = S.fullJustify(str, 3);
	for (auto& s : rst) {
		cout << s << endl;
	}
	return 0;
}
