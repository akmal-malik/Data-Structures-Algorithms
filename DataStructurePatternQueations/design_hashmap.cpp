// Problem: Design HashMap
// ------------------------------------------------------------
// Problem Description:
// Design a HashMap without using any built-in hash table libraries.
// Your HashMap should support basic operations like put, get, and remove.
// ------------------------------------------------------------
// Approach: Separate Chaining
// We use an array of linked lists to store key-value pairs. Each element in the array is a pointer to the head of a linked list.
// The hash function used is the modulo of the key's hash value and the array's size.
// ------------------------------------------------------------
// Time Complexity: 
// put, get, remove: Average O(1), Worst O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int key, val;
    ListNode* next;
    ListNode(int key, int val) : key(key), val(val), next(nullptr) {}
};

class Solution {
private:
    vector<ListNode*> buckets;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    Solution(int capacity = 100) : size(capacity) {
        buckets.resize(size);
    }

    void put(int key, int value) {
        int index = hashFunction(key);
        ListNode* node = buckets[index];
        while (node != nullptr) {
            if (node->key == key) {
                node->val = value;
                return;
            }
            node = node->next;
        }
        ListNode* newNode = new ListNode(key, value);
        newNode->next = buckets[index];
        buckets[index] = newNode;
    }

    int get(int key) {
        int index = hashFunction(key);
        ListNode* node = buckets[index];
        while (node != nullptr) {
            if (node->key == key) {
                return node->val;
            }
            node = node->next;
        }
        return -1; // Key not found
    }

    void remove(int key) {
        int index = hashFunction(key);
        ListNode* node = buckets[index];
        ListNode* prev = nullptr;
        while (node != nullptr) {
            if (node->key == key) {
                if (prev == nullptr) {
                    buckets[index] = node->next;
                } else {
                    prev->next = node->next;
                }
                delete node;
                return;
            }
            prev = node;
            node = node->next;
        }
    }
};