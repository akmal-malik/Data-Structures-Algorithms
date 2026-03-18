// Problem: Sum root to leaf
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, find the sum of all root-to-leaf numbers.
// A leaf is a node with no children.
// ------------------------------------------------------------
// Approach: Depth-First Search (DFS)
// Traverse the tree using DFS, keeping track of the current path sum.
// When reaching a leaf node, add the current path sum to the total sum.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        dfs(root, 0, totalSum);
        return totalSum;
    }

private:
    void dfs(TreeNode* node, int currentSum, int& totalSum) {
        if (!node) return;
        currentSum = currentSum * 10 + node->val;
        if (!node->left && !node->right) {
            totalSum += currentSum;
            return;
        }
        dfs(node->left, currentSum, totalSum);
        dfs(node->right, currentSum, totalSum);
    }
};