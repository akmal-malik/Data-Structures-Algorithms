// Problem: Mathematics (10 problems)
// ------------------------------------------------------------
// Problem Description:
// Given an integer number n, return the difference between the sum of its even digits and the sum of its odd digits.
// Example:
// Input: 123456
// Output: 3 (Even sum = 2+4+6=12; Odd sum = 1+3+5=9; Result = 12-9 = 3)
// ------------------------------------------------------------
// Approach: Iteration and Modulo
// Iterate through each digit of the number, calculate the sum of even and odd digits separately using modulo operation.
// ------------------------------------------------------------
// Time Complexity: O(log n) - Number of digits in the number
// Space Complexity: O(1) - Constant space
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSum(int n) {
        int evenSum = 0, oddSum = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit % 2 == 0)
                evenSum += digit;
            else
                oddSum += digit;
            n /= 10;
        }
        return abs(evenSum - oddSum);
    }
};