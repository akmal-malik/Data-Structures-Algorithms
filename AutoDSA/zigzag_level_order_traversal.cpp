// Problem: Zigzag level order traversal
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, return the zigzag level order traversal of its nodes' values. 
// (i.e., from left to right, then right to left for the next level and alternate between).
// ------------------------------------------------------------
// Approach: Breadth-First Search (BFS) with Direction Toggle
// Perform a breadth-first search (BFS) on the tree. Maintain a queue for level-wise traversal 
// and a boolean flag to toggle the direction of traversal for each level.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the binary tree. 
// Each node is processed once.
// Space Complexity: O(n), for the queue used during the BFS traversal.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                if (leftToRight) {
                    level.push_back(node->val);
                } else {
                    level.insert(level.begin(), node->val);
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(level);
            leftToRight = !leftToRight;
        }
        
        return result;
    }
};