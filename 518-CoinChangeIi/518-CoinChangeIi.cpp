// Last updated: 6/10/2026, 7:24:39 PM
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned int>> dp(amount+1, vector<unsigned int>(n+1, 0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1; 
        for (int i = 1; i <= amount; i++) {
            for (int j = n-1; j >= 0; j--) {
                dp[i][j] = dp[i][j+1]; 
                if (i >= coins[j]) dp[i][j] += dp[i - coins[j]][j]; 
            }
        }
        return dp[amount][0];
    }
};