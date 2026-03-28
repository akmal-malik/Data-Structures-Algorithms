// Problem: Lowest common ancestor BST
// ------------------------------------------------------------
// Problem Description:
// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
// According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes v and w as 
// the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself)."
// ------------------------------------------------------------
// Approach: Recursive
// We can leverage the properties of BST. If both p and q are smaller than the current node, LCA must be in the left subtree.
// Similarly, if both are greater, it must be in the right subtree. Otherwise, the current node is their LCA.
// Time Complexity: O(h), where h is the height of the tree.
// Space Complexity: O(h) due to the recursion stack.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};