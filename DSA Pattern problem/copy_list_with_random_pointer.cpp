// Problem: Copy list with random pointer
// ------------------------------------------------------------
// Problem Description:
// Given a singly linked list where each node has an additional random pointer
// that could point to any node in the list or null. Your task is to make a deep copy
// of the list. The deep copy should have the same value and random pointer as the original.
// The random pointer of the new node should point to the node in the new list
// that corresponds to the random pointer of the original node. If the original node's
// random pointer is null, the new node's random pointer should also be null.
// The copy list should be done in O(n) time complexity and O(1) extra space.
// ------------------------------------------------------------
// Approach: Interweaving and Splitting
// The algorithm first interweaves the original and copied nodes by inserting each
// copy node immediately after its corresponding original node. Then, it adjusts
// the random pointers of the copied nodes. Finally, it splits the interwoven
// list into the original and copied lists.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Interweave the original and copied nodes
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            Node* copy = new Node(curr->val);
            curr->next = copy;
            copy->next = next;
            curr = next;
        }

        // Step 2: Adjust the random pointers of the copied nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Split the interwoven list into the original and copied lists
        Node* newHead = head->next;
        Node* copyCurr = newHead;
        curr = head;
        while (curr) {
            curr->next = copyCurr->next;
            curr = curr->next;
            if (curr) {
                copyCurr->next = curr->next;
                copyCurr = copyCurr->next;
            }
        }

        return newHead;
    }
};