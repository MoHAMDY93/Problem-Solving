// Last updated: 6/10/2026, 7:10:21 PM
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1 , 0);
        for(int j=1 ; j<=n ; j++) {
            dp[j] = INT_MAX;
            for(int i=1 ; i<4 ; i++) {
                if(j - i >= 0) dp[j] = min(dp[j] , dp[j-i] + costs[j-1] + i*i);
            }
        }
        return dp[n];
    }
};