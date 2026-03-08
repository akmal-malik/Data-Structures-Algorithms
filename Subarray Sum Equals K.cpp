// Problem: Subarray Sum Equals K
// ------------------------------------------------------------
// Given an array of integers nums and an integer k, return the
// total number of subarrays whose sum equals to k.
//
// A subarray is a contiguous non-empty sequence of elements
// within an array.
//
// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2
//
// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2
//
// Constraints:
// 1 <= nums.length <= 2 * 10^4
// -1000 <= nums[i] <= 1000
// -10^7 <= k <= 10^7
//
// ------------------------------------------------------------
// Approach: Prefix Sum + Hash Map
//
// We maintain a running prefix sum while iterating through
// the array. If at any index:
//
//      prefixSum - previousPrefix = k
//
// then the subarray between those indices has sum = k.
//
// So we store the frequency of prefix sums in a hashmap.
// For each element:
// 1. Update prefixSum
// 2. Check if (prefixSum - k) exists in the hashmap
// 3. If yes, add its frequency to the count
// 4. Store the current prefixSum in the hashmap
//
// Important:
// Initialize hashmap with mp[0] = 1 to handle cases where
// the subarray starting from index 0 equals k.
//
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // Base case
        
        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};
