/**
 * 61. Rotate List
 *
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 *
 */

#include "showvec.hpp"
#include "showmap.hpp"
#include "showlist.hpp"

// --- include --- // 
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

// --- solution part --- //
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
	public:
		ListNode* rotateRight(ListNode* head, int k) {
			if (head == NULL) return head;
			int N = 1;
			ListNode* p = head;
			while (p->next != NULL) {
				p = p->next;
				++N;
			}

			k = N - k % N;
			if (k == N) return head;

			p = head;
			for (int i = 0; i < k; ++i) {
				p = p->next;
			}

			ListNode* rst, *prst;
			rst = new ListNode(p->val);
			prst = rst;
			p = p->next;
			while (N > 1) {
				if (p == NULL) p = head;
				prst->next = new ListNode(p->val);
				p = p->next;
				prst = prst->next;
				--N;
			}

			return rst;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	ListNode *head, *p;

	head = new ListNode(1);
	p = head;
	p->next = new ListNode(2); p = p->next;
	p->next = new ListNode(3); ;

	showlist(head);
	showlist(S.rotateRight(head, 2000000000));

	return 0;
}
