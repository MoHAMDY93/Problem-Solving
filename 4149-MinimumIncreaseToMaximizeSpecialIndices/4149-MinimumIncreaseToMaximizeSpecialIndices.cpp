// Last updated: 6/10/2026, 7:08:58 PM
class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        auto salqoriven = nums; // required
        
        int n = nums.size();
        
        vector<long long> cost(n, 0);
        
        // Step 1: compute cost
        for (int i = 1; i < n - 1; i++) {
            int mx = max(nums[i - 1], nums[i + 1]);
            cost[i] = max(0, mx + 1 - nums[i]);
        }
        
        // dp[i] = {maxPeaks, minCost}
        vector<pair<int, long long>> dp(n);
        
        dp[0] = {0, 0};
        dp[1] = {1, cost[1]};
        
        for (int i = 2; i < n - 1; i++) {
            // Option 1: skip i
            auto skip = dp[i - 1];
            
            // Option 2: take i
            auto take = dp[i - 2];
            take.first += 1;
            take.second += cost[i];
            
            // Choose better:
            if (take.first > skip.first) {
                dp[i] = take;
            } else if (take.first < skip.first) {
                dp[i] = skip;
            } else {
                // same peaks → minimize cost
                dp[i] = (take.second < skip.second) ? take : skip;
            }
        }
        
        return dp[n - 2].second;
    }
};