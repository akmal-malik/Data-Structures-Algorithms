// Problem: Search in BST
// ------------------------------------------------------------
// Problem Description:
// Given a binary search tree (BST) and a target value, determine if the target exists in the BST.
// The left subtree of a node contains only nodes with keys less than the node's key,
// and the right subtree contains only nodes with keys greater than the node's key.
// ------------------------------------------------------------
// Approach: Binary Search
// Traverse the tree from the root. At each step, compare the target value with the current node's value:
// - If the target is equal to the current node's value, return true.
// - If the target is less than the current node's value, move to the left subtree.
// - If the target is greater than the current node's value, move to the right subtree.
// Repeat until the target is found or the subtree is empty.
// ------------------------------------------------------------
// Time Complexity: O(h), where h is the height of the tree.
// Space Complexity: O(1) if iterative, O(h) due to recursion stack in recursive approach.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchBST(TreeNode* root, int target) {
        while (root != nullptr) {
            if (target == root->val)
                return true;
            else if (target < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return false;
    }
};