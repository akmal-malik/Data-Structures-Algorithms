// Problem: Maximum depth
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, find its maximum depth. The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
// ------------------------------------------------------------
// Approach: Depth-First Search (DFS)
// Perform a depth-first search to traverse the tree. Keep track of the current depth and update the maximum depth encountered.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree due to the recursion stack.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }
};