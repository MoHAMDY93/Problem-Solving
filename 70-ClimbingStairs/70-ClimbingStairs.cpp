// Last updated: 6/10/2026, 7:27:10 PM
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1 , 0);
        // Complexity with (n * k), to keep the summation{j=1 -> j = k}[dp[i]];
        // can be oprimized further using sliding win
        dp[0] = 1;
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=2 ; j++) {
                if(i - j >= 0) dp[i] += dp[i-j];
            }
        }
        return dp[n];
    }
};