// Problem: Number of islands 2
// ------------------------------------------------------------
// Problem Description:
// You are given an m x n grid initially filled with water. We can change the water at some cell into a land (1).
// Given a list of positions to flip each day, return the number of islands formed after each day.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// ------------------------------------------------------------
// Approach: Union-Find Data Structure
// Use the Union-Find data structure to efficiently manage and merge disjoint sets (islands).
// For each position flipped, union it with its neighboring land cells if they exist. Keep track of the number of distinct islands.
// ------------------------------------------------------------
// Time Complexity: O(m * n + k), where m x n is the grid size and k is the number of positions to flip.
// Space Complexity: O(m * n) for storing the Union-Find data structure.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class UF {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UF(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unionSet(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        UF uf(m * n);
        unordered_set<int> land;
        vector<int> result;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (const auto& pos : positions) {
            int x = pos[0], y = pos[1];
            int idx = x * n + y;
            if (!land.count(idx)) {
                land.insert(idx);
                for (const auto& dir : directions) {
                    int nx = x + dir.first, ny = y + dir.second;
                    int nIdx = nx * n + ny;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && land.count(nIdx)) {
                        uf.unionSet(idx, nIdx);
                    }
                }
            }
            result.push_back(land.size() - uf.count());
        }
        
        return result;
    }
};