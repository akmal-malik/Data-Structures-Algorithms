// Problem: Level order traversal
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, return the level order traversal of its nodes' values. 
// (i.e., from left to right, level by level).
// ------------------------------------------------------------
// Approach: Breadth-First Search (BFS)
// Perform a BFS to traverse the tree level by level. 
// Use a queue to keep track of nodes at each level.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(n), for the queue in the worst case.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            result.push_back(vector<int>());
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                result.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
};