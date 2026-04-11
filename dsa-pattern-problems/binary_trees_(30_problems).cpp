// Problem: Binary Trees (30 problems)
// ------------------------------------------------------------
// Problem Description:
// Given the root of a binary tree, determine if it is height-balanced.
// A binary tree in which the depth of the two subtrees of every node never differs by more than one.
// ------------------------------------------------------------
// Approach: Depth-First Search (DFS) with Height Calculation
// Perform DFS to calculate the height of each subtree. If at any point, the difference between the heights of left and right subtrees is greater than 1, return false.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(h), where h is the height of the tree
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (abs(leftHeight - rightHeight) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
};