// Problem: Path sum 2
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
// ------------------------------------------------------------
// Approach: Depth-First Search (DFS)
// We use a DFS approach to explore all root-to-leaf paths. During the traversal, we keep track of the current path and its sum.
// If we reach a leaf node and the current path sum equals the target sum, we add the path to the result.
// ------------------------------------------------------------
// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(H), where H is the height of the tree due to the recursion stack.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        dfs(root, sum, currentPath, result);
        return result;
    }
private:
    void dfs(TreeNode* node, int remainingSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (node == nullptr) return;
        currentPath.push_back(node->val);
        remainingSum -= node->val;
        if (node->left == nullptr && node->right == nullptr && remainingSum == 0) {
            result.push_back(currentPath);
        }
        dfs(node->left, remainingSum, currentPath, result);
        dfs(node->right, remainingSum, currentPath, result);
        currentPath.pop_back();
    }
};