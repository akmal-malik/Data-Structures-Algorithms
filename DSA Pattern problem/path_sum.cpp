// Problem: Path sum
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
// ------------------------------------------------------------
// Approach: Depth-First Search (DFS)
// We will use a depth-first search approach to traverse the binary tree. At each node, we subtract the node's value from the sum. If we reach a leaf node and the sum becomes zero, we return true. Otherwise, we continue to traverse the left and right subtrees.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right && root->val == sum) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};