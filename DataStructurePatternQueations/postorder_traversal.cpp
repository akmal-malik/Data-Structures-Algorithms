// Problem: Postorder traversal
// ------------------------------------------------------------
// Problem Description:
// Given the root of a binary tree, return the postorder traversal of its nodes' values.
// ------------------------------------------------------------
// Approach: Iterative using Stack
// Perform postorder traversal iteratively using a stack. Maintain two stacks. The first stack is used to keep track of nodes to be visited. The second stack is used to store nodes in the order of postorder traversal.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the binary tree.
// Space Complexity: O(n), due to the use of two stacks.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> s1, s2;
        s1.push(root);
        
        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);
            
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        
        while (!s2.empty()) {
            result.push_back(s2.top()->val);
            s2.pop();
        }
        
        return result;
    }
};