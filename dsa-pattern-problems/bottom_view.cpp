// Problem: Bottom view
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, the task is to print the bottom view of the binary tree.
// The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.
// If two nodes are in the same vertical line, then the node which comes last in the vertical order should be considered for the bottom view.
// ------------------------------------------------------------
// Approach: Level Order Traversal with Tracking Horizontal Distance
// Perform a level order traversal of the binary tree. For each node, track its horizontal distance from the root.
// Use a map to store the last node seen at each horizontal distance. This map will give us the bottom view nodes.
// ------------------------------------------------------------
// Time Complexity: O(N), where N is the number of nodes in the binary tree.
// Space Complexity: O(N), for storing the nodes in the map and the queue.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bottomView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        map<int, int> bottomViewMap;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto node = q.front().first;
            int hd = q.front().second;
            q.pop();

            // Update the value of the current horizontal distance
            bottomViewMap[hd] = node->val;

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        // Collect the bottom view from the map
        for (auto& it : bottomViewMap) {
            result.push_back(it.second);
        }

        return result;
    }
};