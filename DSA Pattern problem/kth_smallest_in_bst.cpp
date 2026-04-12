// Problem: Kth smallest in BST
// ------------------------------------------------------------
// Problem Description:
// Given a binary search tree (BST) and an integer k, return the kth smallest element in the BST.
// ------------------------------------------------------------
// Approach: In-order Traversal
// Perform an in-order traversal of the BST which will yield elements in sorted order. Stop after visiting k nodes.
// ------------------------------------------------------------
// Time Complexity: O(k)
// Space Complexity: O(h), where h is the height of the tree due to recursion stack
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        while (true) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
    }
};