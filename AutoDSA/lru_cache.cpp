// Problem: LRU cache
// ------------------------------------------------------------
// Problem Description:
// Design a data structure that follows the Least Recently Used (LRU) cache policy. It should support the following operations: get and put.
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Insert an item into the cache. If the key already exists, then overwrite its value. If the cache reached its capacity, evict the least recently used item before inserting a new item.
// ------------------------------------------------------------
// Approach: Hash Map + Doubly Linked List
// Use a hash map to store the key and the corresponding node in the doubly linked list. The linked list maintains the order of the keys, with the most recently used at the front and the least recently used at the back.
// ------------------------------------------------------------
// Time Complexity: get(key) and put(key, value) both have a time complexity of O(1) on average.
// Space Complexity: O(capacity) for storing the key-value pairs and the linked list.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value;
    Node* prev, *next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* head, *tail;
    int capacity;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            removeNode(node);
            addToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addToHead(node);
        } else {
            if (cache.size() == capacity) {
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            addToHead(newNode);
            cache[key] = newNode;
        }
    }
};