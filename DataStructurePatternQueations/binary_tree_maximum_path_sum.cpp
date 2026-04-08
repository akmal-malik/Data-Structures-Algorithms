// Problem: Binary tree maximum path sum
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.
// A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to pass through the root.
// ------------------------------------------------------------
// Approach: Depth-First Search (DFS)
// Perform a DFS traversal of the tree. At each node, calculate the maximum path sum that can be obtained by including the current node. This involves considering the maximum path sum of the left and right subtrees, and choosing the maximum of these sums, along with the current node's value.
// If the maximum path sum at a node is negative, it is better not to include it in the path, so return 0.
// The global maximum path sum is updated during the DFS traversal.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree. Each node is visited once.
// Space Complexity: O(h), where h is the height of the tree. This is due to the recursion stack.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        maxPathSumHelper(root, result);
        return result;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& result) {
        if (node == nullptr) return 0;

        int left = max(0, maxPathSumHelper(node->left, result));
        int right = max(0, maxPathSumHelper(node->right, result));

        result = max(result, left + right + node->val);
        return max(left, right) + node->val;
    }
};