// Problem: Top view
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, print the top view of the binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
// The top view of a binary tree is the set of nodes at each horizontal distance from the root node. If two nodes are at the same horizontal distance, then the node that appears first from the left in the top view.
// ------------------------------------------------------------
// Approach: Level Order Traversal
// We use a level order traversal to traverse the tree level by level. For each level, we keep track of the nodes at the minimum horizontal distance. We use a map to store the node values at each horizontal distance. We also use a queue to perform the level order traversal.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(n), where n is the number of nodes in the tree.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, int> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int line = p.second;

            if (m.find(line) == m.end()) {
                m[line] = node->val;
            }

            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};