// Problem: Preorder traversal
// ------------------------------------------------------------
// Problem Description:
// Given the root of a binary tree, return the preorder traversal of its nodes' values.
// Preorder traversal means visiting the root node first, then the left subtree, and finally the right subtree.
// ------------------------------------------------------------
// Approach: Recursive
// Use a recursive function to traverse the tree. Visit the root node, then recursively traverse the left subtree, and finally the right subtree.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

private:
    void preorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        result.push_back(node->val);
        preorderHelper(node->left, result);
        preorderHelper(node->right, result);
    }
};