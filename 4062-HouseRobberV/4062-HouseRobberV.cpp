// Last updated: 6/10/2026, 7:10:00 PM
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<long long> dp(n , 0);
        dp[0] = nums[0];
        for (int i=1 ; i<n ; i++) {
            if (colors[i] != colors[i-1])
                dp[i] = max(dp[i-1] , dp[i-1] + nums[i]);
            else if(i > 1)
                dp[i] = max(dp[i-1] , dp[i-2] + nums[i]);
            else 
                dp[i] = max(nums[0] , nums[1]);
        }
        return dp[n-1];
    }
};