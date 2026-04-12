// Problem: LFU cache
// ------------------------------------------------------------
// Problem Description:
// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys have the same frequency), the least recently used key should be evicted.
// Note that the number of times an item is used is the number of times get and put are called with this item.
// ------------------------------------------------------------
// Approach: Hash Map + Doubly Linked List
// Use a hash map to store the frequency and a doubly linked list to store the keys. The doubly linked list is ordered by frequency, and each node in the list contains a doubly linked list of keys with the same frequency.
// ------------------------------------------------------------
// Time Complexity: O(1) for both get and put operations.
// Space Complexity: O(capacity)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int value;
    int frequency;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), frequency(1), prev(NULL), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() : head(NULL), tail(NULL), size(0) {}

    void add(Node* node) {
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }

    void remove(Node* node) {
        if (node->prev != NULL) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if (node->next != NULL) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        size--;
    }
};

class LFUCache {
public:
    unordered_map<int, Node*> keyToNode;
    unordered_map<int, LinkedList*> frequencyList;
    int capacity;
    int minFrequency;

    LFUCache(int capacity) : capacity(capacity), minFrequency(0) {}

    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }
        Node* node = keyToNode[key];
        update(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        if (keyToNode.find(key) != keyToNode.end()) {
            Node* node = keyToNode[key];
            node->value = value;
            update(node);
            return;
        }
        if (keyToNode.size() == capacity) {
            LinkedList* list = frequencyList[minFrequency];
            Node* nodeToRemove = list->head;
            keyToNode.erase(nodeToRemove->key);
            list->remove(nodeToRemove);
            if (list->size == 0) {
                frequencyList.erase(minFrequency);
            }
        }
        Node* newNode = new Node(key, value);
        keyToNode[key] = newNode;
        frequencyList[1]->add(newNode);
        minFrequency = 1;
    }

    void update(Node* node) {
        int frequency = node->frequency;
        LinkedList* list = frequencyList[frequency];
        list->remove(node);
        if (frequency == minFrequency && list->size == 0) {
            minFrequency++;
        }
        frequency++;
        node->frequency = frequency;
        frequencyList[frequency]->add(node);
    }
};