// Problem: Right side view
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// ------------------------------------------------------------
// Approach: Depth-First Search (DFS)
// Perform a depth-first traversal (pre-order) where we traverse the right subtree before the left subtree. This ensures that when we encounter a node at a depth for which we haven't added a node to the result yet, it will be the rightmost node visible at that depth.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(h), where h is the height of the binary tree due to the recursion stack.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
private:
    void dfs(TreeNode* node, int depth, vector<int>& result) {
        if (node == nullptr) return;
        if (depth == result.size()) result.push_back(node->val);
        dfs(node->right, depth + 1, result);
        dfs(node->left, depth + 1, result);
    }
};