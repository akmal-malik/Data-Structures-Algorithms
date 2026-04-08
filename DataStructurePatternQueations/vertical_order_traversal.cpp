// Problem: Vertical order traversal
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, return the vertical order traversal of its nodes' values. 
// (i.e., from top to bottom, column by column).
// If two nodes are in the same row and column, the order should be from left to right.
// ------------------------------------------------------------
// Approach: BFS with Map and Pair
// Use BFS to traverse the tree level by level. Use a map to store the nodes' values 
// based on their vertical order. Store each node as a pair of its column index and node value.
// ------------------------------------------------------------
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        map<int, vector<int>> mp; // map to store nodes based on their vertical order
        queue<pair<TreeNode*, int>> q; // queue for BFS
        q.push({root, 0}); // start BFS from root node
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int hd = p.second;
            
            mp[hd].push_back(node->val);
            
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        for (auto p : mp) {
            result.push_back(p.second);
        }
        
        return result;
    }
};