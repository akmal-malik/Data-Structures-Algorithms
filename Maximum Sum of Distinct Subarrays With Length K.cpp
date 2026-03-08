// Problem: Maximum Sum of Distinct Subarrays With Length K
// ------------------------------------------------------------
// You are given an integer array nums and an integer k.
//
// Find the maximum subarray sum of all subarrays that satisfy:
// 1. The length of the subarray is exactly k
// 2. All elements in the subarray are distinct
//
// Return the maximum sum of such subarrays.
// If no valid subarray exists, return 0.
//
// A subarray is a contiguous non-empty sequence of elements.
//
// Example 1:
// Input: nums = [1,5,4,2,9,9,9], k = 3
// Output: 15
//
// Valid subarrays:
// [1,5,4] -> sum = 10
// [5,4,2] -> sum = 11
// [4,2,9] -> sum = 15
//
// Subarrays like [2,9,9] and [9,9,9] are invalid because
// elements are not distinct.
//
// Example 2:
// Input: nums = [4,4,4], k = 3
// Output: 0
//
// ------------------------------------------------------------
// Approach: Sliding Window + Hash Map
//
// We maintain a sliding window of size k.
//
// Steps:
// 1. Expand the window by adding nums[right]
// 2. Track frequency of elements using a hashmap
// 3. Maintain the running sum of the window
// 4. If window size exceeds k, remove nums[left]
// 5. If window size == k and all elements are distinct
//    (freq.size() == k), update the maximum sum
//
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(k)
// ------------------------------------------------------------

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long sum = 0;
        long long maxSum = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            freq[nums[right]]++;
            sum += nums[right];

            if(right - left + 1 > k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            if(right - left + 1 == k && freq.size() == k){
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
