// Problem: Flatten multilevel doubly linked list
// ------------------------------------------------------------
// Problem Description:
// You are given a multilevel doubly linked list where each node has two pointers, next and child. The next pointer points to the next node in the list, while the child pointer can point to a child list. Your task is to flatten the list so that all nodes appear in a single level, with each node's next pointer pointing to the next node in the flattened list, and each node's child pointer set to null.
// ------------------------------------------------------------
// Approach: Iterative
// The iterative approach involves using a stack to keep track of nodes. We start from the head and iterate through the list. If we encounter a node with a child, we push the current next node onto the stack and update the next pointer of the current node to the child node. If the current node has no child, we continue to the next node. When we encounter a null next pointer, we pop a node from the stack and link it to the current node's next pointer. We repeat this process until the end of the list is reached and the stack is empty.
// ------------------------------------------------------------
// Time Complexity: O(N), where N is the total number of nodes in the list.
// Space Complexity: O(N) due to the stack used for storing next pointers of nodes with children.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        stack<Node*> st;
        while (curr || !st.empty()) {
            if (curr->child) {
                if (curr->next) st.push(curr->next);
                curr->next = curr->child;
                curr->child = nullptr;
                curr->next->prev = curr;
            } else if (!curr->next) {
                if (!st.empty()) {
                    Node* next = st.top();
                    st.pop();
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};