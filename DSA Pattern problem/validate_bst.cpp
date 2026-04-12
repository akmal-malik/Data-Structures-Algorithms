// Problem: Validate BST
// ------------------------------------------------------------
// Problem Description:
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// - The left subtree of a node contains only nodes with keys less than the node’s key.
// - The right subtree of a node contains only nodes with keys greater than the node’s key.
// - Both the left and right subtrees must also be binary search trees.
// ------------------------------------------------------------
// Approach: In-order Traversal
// Perform an in-order traversal of the tree. If the elements are not strictly increasing, the tree is not a valid BST.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree due to recursion stack.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        
        vector<int> inorder;
        inOrderTraversal(root, inorder);
        
        for (int i = 1; i < inorder.size(); ++i) {
            if (inorder[i] <= inorder[i - 1]) return false;
        }
        
        return true;
    }

private:
    void inOrderTraversal(TreeNode* root, vector<int>& inorder) {
        if (root == nullptr) return;
        
        inOrderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inOrderTraversal(root->right, inorder);
    }
};
