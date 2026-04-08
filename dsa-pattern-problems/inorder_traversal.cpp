// Problem: Inorder traversal
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, return the inorder traversal of its nodes' values.
// ------------------------------------------------------------
// Approach: Recursive
// Use a stack to simulate the recursive call stack.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(h), where h is the height of the tree.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        while (root != NULL || !stack.empty()) {
            while (root != NULL) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};