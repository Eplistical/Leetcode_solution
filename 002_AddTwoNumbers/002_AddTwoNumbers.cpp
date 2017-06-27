/**
 * 2. Add Two Numbers
 *
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

#include "showvec.hpp"

// --- include --- // 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// --- solution part --- //
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			int extra = 0;
			int val, val1, val2;
			ListNode* head = new ListNode(0);
			ListNode* rst = head;

			while(l1 != NULL or l2 != NULL) {
				if (l1 == NULL) {
					val1 = 0;
				}
				else {
					val1 = l1->val;
					l1 = l1->next;
				}

				if (l2 == NULL) {
					val2 = 0;
				}
				else {
					val2 = l2->val;
					l2 = l2->next;
				}

				val = val1 + val2 + extra;
				if (val >= 10) {
					val -= 10;
					extra = 1;
				}
				else {
					extra = 0;
				}

				rst->next = new ListNode(val);
				rst = rst->next;
			}
			if (extra == 1) rst->next = new ListNode(1);
			return head->next;
		}
};

// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	ListNode* l1 = new ListNode(5);

	ListNode* l2 = new ListNode(5);

	ListNode* rst = S.addTwoNumbers(l1, l2);
	while(rst != NULL) {
		cout << rst->val << "\t";
		rst = rst->next;
	}
	return 0;
}
