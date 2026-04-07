// 🔥 Maximum Profit in Job Scheduling (LeetCode)

// 🧠 Problem:
// Each job has:
// startTime[i], endTime[i], profit[i]
// You cannot take overlapping jobs
// You CAN start a job exactly when another ends

// 🎯 Goal:
// Maximize total profit

// 🚀 Approach: DP + Binary Search (Weighted Interval Scheduling)

// 💡 Key Idea:
// For each job, we have 2 choices:
// 1. Take the job → add profit + next non-overlapping job
// 2. Skip the job

// We use DP from right to left

// 🧩 Steps:
// 1. Combine jobs into a single array
// 2. Sort jobs by start time
// 3. For each job:
//    - Use binary search to find next valid job
// 4. DP[i] = max(take, skip)

// 🔍 Why Binary Search?
// Because we need to quickly find the next job whose start >= current end

// ⏱ Complexity:
// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        
        // Step 1: Create jobs array → {start, end, profit}
        vector<vector<int>> jobs;
        for(int i = 0; i < n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        // Step 2: Sort jobs by start time
        sort(jobs.begin(), jobs.end());
        
        // Step 3: DP array
        vector<int> dp(n);
        
        // Base case: last job profit
        dp[n - 1] = jobs[n - 1][2];
        
        // Step 4: Iterate backwards
        for(int i = n - 2; i >= 0; i--){
            
            // Find next non-overlapping job
            int nextIndex = binarySearch(jobs, jobs[i][1]);
            
            // Option 1: Take current job
            int take = jobs[i][2];
            if(nextIndex < n){
                take += dp[nextIndex];
            }
            
            // Option 2: Skip current job
            int skip = dp[i + 1];
            
            // Store best result
            dp[i] = max(take, skip);
        }
        
        // Final answer
        return dp[0];
    }
    
private:
    // 🔍 Binary Search:
    // Find first job with start >= target (end time)
    int binarySearch(vector<vector<int>>& jobs, int target){
        int low = 0, high = jobs.size() - 1;
        int ans = jobs.size();
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(jobs[mid][0] >= target){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
