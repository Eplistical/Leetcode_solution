/**
 * 25. Reverse Nodes in k-Group
 *
 * Given a linked list, 
 * reverse the nodes of a linked list k at a time and return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 *
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

// --- solution part --- //
class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			if (k == 1) return head;
			if (head == NULL) return head;
			ListNode *tag, *p1, *p2;
			ListNode *thehead, *newhead, *newend, *nextbegin;
			ListNode *segbegin, *segend;

			newhead = NULL;
			newend = NULL;
			segend = segbegin = head;
			bool endnow = false;

			while(true) {
				for (size_t i = 0; i < k - 1; ++i) {
					segend = segend->next;
					if (segend == NULL) {
						endnow = true;
						break;
					}
				}
				if (endnow) break;

				tag = segbegin;
				p1 = tag->next;
				p2 = p1->next;
				while(p1 != segend) {
					p1->next = tag;
					tag = p1;
					p1 = p2;
					p2 = p2->next;
				}
				p1->next = tag;

				if (newend == NULL) {
					newhead = segend;
					newend = segbegin;
					newend->next = NULL;
				}
				else {
					newend->next = segend;
					newend = segbegin;
					newend->next = NULL;
				}
				segend = segbegin = p2;
				if (segend == NULL) break;
			}
			if (newhead == NULL) return head;
			newend->next = segbegin;
			return newhead;
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	ListNode *head = new ListNode(0);
	ListNode *p;
	int k;
	p = head;
	for (k = 0; k < 10; ++k) {
		p->next = new ListNode(k + 1);
		p = p->next;
	}
	p = head;
	while(p != NULL){
		cout << p->val << "->";
		p = p->next;
	}
	cout << "(end)" << endl;

	k = 1;
	ListNode *rst = S.reverseKGroup(head, k);

	p = rst;
	while(p != NULL){
		cout << p->val << "->";
		p = p->next;
	}
	cout << "(end)" << endl;


	return 0;
}
