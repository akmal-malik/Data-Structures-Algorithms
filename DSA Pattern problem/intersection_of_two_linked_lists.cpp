// Problem: Intersection of two linked lists
// ------------------------------------------------------------
// Problem Description:
// Given two singly linked lists, determine if the two lists intersect. Return the intersecting node. If the two lists do not intersect, return null.
// ------------------------------------------------------------
// Approach: Two Pointers
// Use two pointers, one starting at the head of each list. When a pointer reaches the end of a list, redirect it to the head of the other list. This way, if there is an intersection, both pointers will meet at the intersection node after traversing the same distance.
// ------------------------------------------------------------
// Time Complexity: O(m + n), where m and n are the lengths of the two lists.
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *a = headA;
        ListNode *b = headB;

        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        return a;
    }
};