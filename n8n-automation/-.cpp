// Problem: Add Two Numbers
// ------------------------------------------------------------
// Problem Description:
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
//
// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
//
// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]
//
// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
//
// Constraints:
// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros, except for the number 0 itself.
//
// ------------------------------------------------------------
// Approach: Iteration with Carry
//
// The problem asks us to add two numbers represented by linked lists, where each digit is stored in a node
// and the digits are in reverse order (e.g., 342 is represented as 2->4->3). This is a common pattern
// that can be solved by simulating the manual process of addition, digit by digit, from right to left,
// while managing a carry-over.
//
// 1.  Initialize a `dummyHead` node. This node simplifies the logic for creating the new linked list,
//     especially handling the first node. We will return `dummyHead->next` as the actual head of the sum list.
// 2.  Initialize a `current` pointer to `dummyHead`. This pointer will be used to build the new list by
//     appending new nodes.
// 3.  Initialize an integer `carry` to 0. This variable will store any carry-over from the sum of two digits.
// 4.  Start a loop that continues as long as there are remaining digits in either `l1` or `l2`,
//     or if there is a `carry` from the previous addition. This ensures all digits and any final carry are processed.
// 5.  Inside the loop:
//     a.  Retrieve the value of the current node from `l1`. If `l1` is null (meaning one list is shorter),
//         treat its value as 0.
//     b.  Retrieve the value of the current node from `l2`. Similarly, if `l2` is null, treat its value as 0.
//     c.  Calculate the `sum` of `val1`, `val2`, and the `carry` from the previous step.
//     d.  Update the `carry` for the next iteration: `carry = sum / 10`.
//     e.  Create a new `ListNode` with the value `sum % 10` (the unit digit of the sum).
//     f.  Append this new node to the `current` pointer's `next`: `current->next = newNode`.
//     g.  Move the `current` pointer to the newly added node: `current = current->next`.
//     h.  Advance `l1` and `l2` to their next nodes, if they are not null.
// 6.  After the loop finishes, return `dummyHead->next`, which points to the first actual digit of the sum.
//
// This approach effectively simulates manual column addition, handling varying list lengths and carries efficiently.
//
// ------------------------------------------------------------
// Time Complexity: O(max(m, n))
// Where m and n are the lengths of the linked lists `l1` and `l2` respectively.
// The algorithm iterates through both lists at most once. In each iteration, constant time operations are performed.
// Therefore, the total time complexity is proportional to the length of the longer list.
// Space Complexity: O(max(m, n))
// The space complexity is determined by the size of the new linked list created to store the sum.
// In the worst case, the sum list can have `max(m, n) + 1` nodes (e.g., if adding 99 + 1 results in 100,
// an extra node for the leading 1 is needed). Thus, the space used is proportional to the length of the longer input list.
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x, next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head node for the result linked list.
        // This simplifies the logic of adding the first node, avoiding special checks for an empty list.
        ListNode* dummyHead = new ListNode(0);
        // `current` pointer will be used to traverse and build the new list.
        ListNode* current = dummyHead;
        // `carry` stores any carry-over value from the sum of digits.
        int carry = 0;

        // Loop continues as long as there are digits in either list or a carry needs to be processed.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the value of the current node from l1. If l1 is null, it means we've
            // exhausted that list, so treat its current digit as 0.
            int val1 = (l1 != nullptr) ? l1->val : 0;
            // Get the value of the current node from l2. Similar logic to l1.
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum of the current digits from both lists and the carry from the previous step.
            int sum = val1 + val2 + carry;

            // Update the carry for the next iteration.
            // For example, if sum is 15, carry becomes 1. If sum is 7, carry becomes 0.
            carry = sum / 10;

            // Create a new node with the unit digit of the sum (e.g., if sum is 15, newNode->val becomes 5).
            // Append this new node to the `next` of the `current` node in our result list.
            current->next = new ListNode(sum % 10);
            // Move the `current` pointer to the newly created node, preparing for the next digit.
            current = current->next;

            // Advance `l1` and `l2` to their next nodes, if they exist, to process the next digits.
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        // The actual head of the result list is `dummyHead->next`.
        // The `dummyHead` itself was just a placeholder to simplify list construction.
        return dummyHead->next;
    }
};