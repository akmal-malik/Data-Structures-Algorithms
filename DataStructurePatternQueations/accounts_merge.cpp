// Problem: Accounts merge
// ------------------------------------------------------------
// Problem Description:
// Given a list of accounts where each account consists of an email address and a 
// list of its sub-accounts (which may contain duplicate emails), the task is to merge 
// all the sub-accounts that share at least one email with another sub-account into 
// a single account. The final output should be a list of merged accounts, where each 
// account consists of a name and a sorted list of unique email addresses.
// ------------------------------------------------------------
// Approach: Union-Find
// Use union-find data structure to group emails that belong to the same account. 
// Traverse through all accounts and merge sub-accounts based on shared emails.
// ------------------------------------------------------------
// Time Complexity: O(N log N), where N is the total number of emails across all accounts.
// Space Complexity: O(N) for storing Union-Find structures and other data.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, int> emailToIndex;
        int id = 0;
        
        for (const auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                string email = account[i];
                if (!emailToName.count(email)) {
                    emailToName[email] = name;
                    emailToIndex[email] = id++;
                }
            }
        }
        
        UnionFind uf(id);
        unordered_map<int, vector<string>> idToEmails;
        
        for (const auto& account : accounts) {
            string firstEmail = account[1];
            int root = emailToIndex[firstEmail];
            for (int i = 2; i < account.size(); ++i) {
                string email = account[i];
                int index = emailToIndex[email];
                uf.unionSet(root, index);
            }
        }
        
        for (const auto& [email, index] : emailToIndex) {
            int root = uf.find(index);
            idToEmails[root].push_back(email);
        }
        
        vector<vector<string>> result;
        for (auto& [_, emails] : idToEmails) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[emails.front()]);
            result.push_back(emails);
        }
        
        return result;
    }
    
private:
    class UnionFind {
    public:
        UnionFind(int size) : parent(size), rank(size, 1) {}
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void unionSet(int x, int y) {
            int rootX = find(x), rootY = find(y);
            if (rootX == rootY) return;
            if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                ++rank[rootX];
            }
        }
    private:
        vector<int> parent, rank;
    };
};