// Problem: Binary tree cameras
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, we install security cameras on the nodes of the tree. 
// Each camera at a node can monitor its parent, itself, and its children. 
// Determine the minimum number of cameras needed to cover all nodes.
// ------------------------------------------------------------
// Approach: Greedy with Postorder Traversal
// Perform postorder traversal to calculate the minimum cameras required from each node's subtree.
// Use states: -1 (covered by a camera), 0 (needs a camera), 1 (has a camera).
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int cameras = 0;
    
    // Returns -1 if covered, 0 if needs a camera, and 1 if has a camera
    int dfs(TreeNode* node) {
        if (node == nullptr)
            return -1; // Base case: null nodes are covered by default
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        // If either child needs a camera, then this node must have a camera
        if (left == 0 || right == 0) {
            cameras++;
            return 1;
        }
        // If at least one child has a camera, then this node is covered
        else if (left == 1 || right == 1)
            return -1;
        // Otherwise, this node needs a camera
        else
            return 0;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        int rootNeedsCamera = dfs(root);
        // If the root itself needs a camera after traversal, add one more camera
        return cameras + (rootNeedsCamera == 0);
    }
};