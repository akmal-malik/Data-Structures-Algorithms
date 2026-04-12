// Problem: Flatten binary tree to Linked List
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, flatten it to a linked list in-place.
// The "linked list" should use the same TreeNode class where 
// the right child pointer points to the next node in the list and 
// the left child pointer is always null.
// The "flattened" tree should look like:
//     1
//      \
//       2 -> 3 -> 4 -> 5 -> 6
// ------------------------------------------------------------
// Approach: Recursive Preorder Traversal
// Perform a preorder traversal (root, right, left) and adjust 
// pointers to form the linked list.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree due to recursion stack.
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* prev = nullptr;
    
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        
        // Store right subtree
        TreeNode* right = root->right;
        
        // If there is a left child, make it the new right child and flatten it
        if (root->left != nullptr) {
            root->right = root->left;
            root->left = nullptr;
            flatten(root->right);
        }
        
        // Recursively flatten the original right subtree
        flatten(right);
        
        // If there is a previous node, link it to the current node
        if (prev != nullptr) {
            prev->right = root;
        }
        
        // Update prev to the current node
        prev = root;
    }
};