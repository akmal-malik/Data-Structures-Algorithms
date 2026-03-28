// Problem: Construct from preorder and postorder
// ------------------------------------------------------------
// Problem Description:
// Given two integer arrays, preorder and postorder, where preorder is the preorder traversal of a binary tree, 
// and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
// Note: It is guaranteed that there is exactly one valid answer.
// ------------------------------------------------------------
// Approach: Recursive Construction
// Construct the tree recursively using the properties of preorder and postorder traversals. 
// The first element in preorder is the root, and the last element in postorder is also the root.
// ------------------------------------------------------------
// Time Complexity: O(n^2) in the worst case due to the linear search for the index in each recursive call
// Space Complexity: O(n) for storing the recursion stack and tree nodes
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(pre[0]);
        if (pre.size() == 1) return root;
        
        int leftRootVal = pre[1];
        auto leftRootIt = find(post.begin(), post.end(), leftRootVal);
        int leftSize = distance(post.begin(), leftRootIt) + 1;
        
        vector<int> leftPre(pre.begin() + 1, pre.begin() + 1 + leftSize);
        vector<int> rightPre(pre.begin() + 1 + leftSize, pre.end());
        
        vector<int> leftPost(post.begin(), post.begin() + leftSize);
        vector<int> rightPost(post.begin() + leftSize, post.end() - 1);
        
        root->left = constructFromPrePost(leftPre, leftPost);
        root->right = constructFromPrePost(rightPre, rightPost);
        
        return root;
    }
};