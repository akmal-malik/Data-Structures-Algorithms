// Problem: Serialize and deserialize
// ------------------------------------------------------------
// Problem Description:
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your 
// serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be 
// serialized to a string and this string can be deserialized to the original tree structure.
// ------------------------------------------------------------
// Approach: Preorder Traversal
// Use preorder traversal to serialize the tree, where null nodes are marked by a special character 
// (e.g., '#'). During deserialization, reconstruct the tree using the pre-order string.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree. The recursion stack space.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialHelper(ss);
    }
private:
    TreeNode* deserialHelper(stringstream& ss) {
        string val;
        getline(ss, val, ',');
        if (val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialHelper(ss);
        root->right = deserialHelper(ss);
        return root;
    }
};