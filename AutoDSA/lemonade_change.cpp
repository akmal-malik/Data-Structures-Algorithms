// Problem: Lemonade change
// ------------------------------------------------------------
// Problem Description:
// At a lemonade stand, each lemonade costs $5. Customers are given cash in any amount and can only receive one lemonade per transaction.
// You must give back the correct change to each customer so that you always have the right bills on hand. 
// Initially, you have no money and all your lemonades are fresh.
// Write a function that returns true if you can provide every customer with correct change.
// ------------------------------------------------------------
// Approach: Greedy Algorithm
// Use a greedy approach to keep track of the number of $5 and $10 bills we have. 
// For each transaction, try to give out the largest bill possible (i.e., $10 first) to minimize the number of bills used.
// If it's not possible to give the correct change with what we have, return false.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};