// 🔥 Candy Distribution (LeetCode)

// 🧠 Problem:
// Each child has a rating
// Rules:
// 1. Each child must get at least 1 candy
// 2. Higher rating than neighbor → more candies

// 🎯 Goal:
// Minimize total candies

// 🚀 Approach: Greedy (Two Pass)

// 💡 Key Idea:
// We must satisfy BOTH:
// - Left neighbor condition
// - Right neighbor condition

// So we do 2 passes:
// 1. Left → Right → handle increasing slope
// 2. Right → Left → handle decreasing slope

// 🧩 Steps:
// 1. Initialize all candies = 1
// 2. Left → Right:
//    If rating[i] > rating[i-1]
//    → candies[i] = candies[i-1] + 1
// 3. Right → Left:
//    If rating[i] > rating[i+1]
//    → candies[i] = max(current, candies[i+1] + 1)
// 4. Sum all candies

// 🧠 Example:
// ratings = [1,0,2]
//
// Step 1: candies = [1,1,1]
//
// Left pass:
// no change → [1,1,1]
//
// Right pass:
// index 0 > index 1 → candies[0] = 2
// index 2 > index 1 → candies[2] = 2
//
// Final: [2,1,2] → sum = 5

// ⏱ Complexity:
// Time: O(n)
// Space: O(n)

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        
        // Step 1: Give each child 1 candy
        vector<int> candies(n, 1);
        
        // Step 2: Left → Right pass
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // Step 3: Right → Left pass
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                // Take max to satisfy both sides
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        // Step 4: Total candies
        int total = 0;
        for(int c : candies){
            total += c;
        }
        
        return total;
    }
};
