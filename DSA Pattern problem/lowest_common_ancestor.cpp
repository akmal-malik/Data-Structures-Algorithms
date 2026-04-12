// Problem: Lowest common ancestor
// ------------------------------------------------------------
// Problem Description:
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// The lowest common ancestor is the deepest node that has both nodes as descendants.
// ------------------------------------------------------------ 
// Approach: Recursive Traversal
// Traverse the tree to find the paths from the root to both nodes.
// Compare these paths to find the last common node before they diverge.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree due to recursion stack.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool findPath(TreeNode* root, vector<TreeNode*>& path, TreeNode* target) {
        if (root == NULL) return false;
        path.push_back(root);
        if (root->val == target->val || findPath(root->left, path, target) ||
            findPath(root->right, path, target)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        if (!findPath(root, path1, p) || !findPath(root, path2, q)) {
            return NULL; // One or both nodes are not present in the tree
        }
        int i = 0;
        while (i < path1.size() && i < path2.size()) {
            if (path1[i] != path2[i]) break;
            i++;
        }
        return path1[i-1];
    }
};