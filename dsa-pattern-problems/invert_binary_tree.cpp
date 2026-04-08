// Problem: Invert binary tree
// ------------------------------------------------------------
// Problem Description:
// Given the root of a binary tree, invert the tree, and return its root.
// The inversion of a binary tree swaps the left and right children of all nodes.
// ------------------------------------------------------------
// Approach: Recursive Inversion
// Traverse the tree recursively and swap the left and right children of each node.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree (due to recursion stack).
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;
        
        // Swap the left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};