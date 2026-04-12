// Problem: All possible full binary trees
// ------------------------------------------------------------
// Problem Description:
// Given an integer n, return a list of all possible full binary trees with n nodes. Each node of each tree in the answer must have Node.val == 0.
// A full binary tree is a binary tree where each node has either 0 or 2 children.
// Note that the number of nodes in this tree will be between 1 and 2^n - 1.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// Use memoization to store intermediate results for different values of n. The base case is when n = 1, which returns a single tree with one node. For each other value of n, recursively generate all possible left and right subtrees and combine them to form full binary trees.
// ------------------------------------------------------------
// Time Complexity: O(2^n) - Each node can have up to two children, leading to exponential growth in the number of trees.
// Space Complexity: O(n * 2^n) - Store all generated trees in a vector.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {}; // Return empty vector for even n, as it's not possible to form a full binary tree with an even number of nodes.
        
        unordered_map<int, vector<TreeNode*>> memo; // Memoization map to store results.
        
        function<vector<TreeNode*> (int)> dp = [&](int nn) {
            if (nn == 1) return {new TreeNode(0)}; // Base case: single node tree.
            if (memo.find(nn) != memo.end()) return memo[nn]; // Return cached result if available.
            
            vector<TreeNode*> res;
            for (int i = 1; i < nn - 1; i += 2) {
                auto leftTrees = dp(i);
                auto rightTrees = dp(nn - i - 1);
                
                for (auto& left : leftTrees) {
                    for (auto& right : rightTrees) {
                        res.push_back(new TreeNode(0, left, right));
                    }
                }
            }
            
            memo[nn] = res; // Cache the result.
            return res;
        };
        
        return dp(n);
    }
};