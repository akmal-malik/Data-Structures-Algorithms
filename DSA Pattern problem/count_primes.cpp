// Problem: Count primes
// ------------------------------------------------------------
// Problem Description:
// Given an integer n, return the number of prime numbers less than n.
// ------------------------------------------------------------
// Approach: Sieve of Eratosthenes
// This algorithm iteratively marks the multiples of each prime number starting from 2, 3, 4, and so on. 
// It efficiently counts the number of prime numbers less than n.
// ------------------------------------------------------------
// Time Complexity: O(n log(log n))
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i < n; ++i) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        int count = 0;
        for (bool p : prime) {
            if (p) count++;
        }
        return count;
    }
};