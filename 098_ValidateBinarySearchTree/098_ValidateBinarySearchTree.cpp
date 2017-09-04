/**
 * 98. Validate Binary Search Tree
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
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
#include <limits> 
using namespace std;

// --- solution part --- //
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		bool isValidBST_(TreeNode* node, long Min, long Max) {
			if (node == NULL) return true;

			if (node->left != NULL) {
				if (node->left->val >= node->val) {
					return false;
				}
				else if (node->left->val <= Min) {
					return false;
				}
				else if (!isValidBST_(node->left, Min, node->val)) {
					return false;
				}
			}

			if (node->right != NULL) {
				if (node->right->val <= node->val) {
					return false;
				}
				else if (node->right->val >= Max) {
					return false;
				}
				else if (!isValidBST_(node->right, node->val, Max)) {
					return false;
				}
			}

			return true;
		}

		bool isValidBST(TreeNode* root) {
			return isValidBST_(root, numeric_limits<long>::min(), numeric_limits<long>::max());
		}
};


// --- test part ---//
int main(int argc, char** argv) {
	Solution S;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(3);

	root->right = new TreeNode(5);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(6);
	cout << S.isValidBST(root) << "\n";
	return 0;
}
