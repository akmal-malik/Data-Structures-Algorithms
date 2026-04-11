// Problem: Tries (8 problems)
// ------------------------------------------------------------
// Problem Description:
// Implement a Trie (prefix tree) data structure.
// It should have functions to insert a word, search for a word, and check if there is any word in the trie that starts with the given prefix.
// ------------------------------------------------------------

// Approach: Prefix Tree
// This approach involves creating a TrieNode class to represent each node in the trie. Each node will contain an array of pointers to its children (one for each character), a flag to mark the end of a word, and other necessary data fields.
// ------------------------------------------------------------
// Time Complexity:
// - Insert: O(m) where m is the length of the word
// - Search: O(m)
// - Prefix: O(p) where p is the length of the prefix
// ------------------------------------------------------------
// Space Complexity: O(n * m) where n is the number of words and m is the average length of a word
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26];

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c - 'a']) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c - 'a']) return false;
            current = current->children[c - 'a'];
        }
        return current->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (!current->children[c - 'a']) return false;
            current = current->children[c - 'a'];
        }
        return true;
    }
};