// Problem: Balanced binary tree
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, determine if it is height-balanced.
// A binary tree in which the depth of the two subtrees of every node never differs by more than 1.
// ------------------------------------------------------------
// Approach: Recursion with Height Calculation
// Calculate the height of the left and right subtrees for each node and check if the difference is at most 1.
// Recursively apply this check to all nodes.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(h), where h is the height of the tree
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the height of the tree
    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    // Function to check if the tree is balanced
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;
    }
};