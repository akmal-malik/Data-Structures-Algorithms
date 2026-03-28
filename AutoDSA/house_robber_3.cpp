// Problem: House robber 3
// ------------------------------------------------------------
// Problem Description:
// The thief has found himself a new place for his thievery again. 
// There is only one entrance to this area, called the "root."
// Besides the root, each house has one and only one parent house. 
// After a tour, the smart thief realized that all houses in this place are arranged in a binary tree.
// To maximize profit, he decided to take some of the houses but without alerting the police.
// The thief cannot rob two directly-linked houses (parent-child). Given the root of the binary tree, return the maximum amount of money the thief can rob tonight without alerting the police.
// ------------------------------------------------------------
// Approach: Dynamic Programming with Memoization
// Use a hash map to store the results of subproblems to avoid redundant calculations.
// For each node, decide whether to rob it or not based on the maximum profit obtained from its children.
// If we rob the current node, we cannot rob its children; otherwise, we consider robbing its children.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is processed once.
// Space Complexity: O(h), where h is the height of the binary tree due to the recursion stack and memoization map.
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
    unordered_map<TreeNode*, int> memo;
    
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (memo.find(root) != memo.end()) return memo[root];
        
        // Rob the current node
        int robCurrent = root->val + 
                          (root->left ? rob(root->left->left) + rob(root->left->right) : 0) +
                          (root->right ? rob(root->right->left) + rob(root->right->right) : 0);
        
        // Do not rob the current node
        int doNotRobCurrent = rob(root->left) + rob(root->right);
        
        memo[root] = max(robCurrent, doNotRobCurrent);
        return memo[root];
    }
};