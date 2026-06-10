// Last updated: 6/10/2026, 7:12:42 PM
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size() , m = coins[0].size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(m , vector<int>(3 , INT_MIN)));
        for (int k=0 ; k<3 ; k++) {
            if (coins[0][0] > 0) dp[0][0][k] = coins[0][0];
            else {
                if (k == 0) dp[0][0][k] = coins[0][0];
                else dp[0][0][k] = 0;
            }
        }
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                for (int k=0 ; k<3 ;k++) {
                    if (i > 0) {
                        dp[i][j][k] = max(dp[i-1][j][k] + coins[i][j] , dp[i][j][k]);
                        if (coins[i][j] < 0 && k > 0)
                            dp[i][j][k] = max(dp[i-1][j][k-1] , dp[i][j][k]);
                    }
                    if (j > 0) {
                        dp[i][j][k] = max(dp[i][j-1][k] + coins[i][j] , dp[i][j][k]);
                        if (coins[i][j] < 0 && k > 0)
                            dp[i][j][k] = max(dp[i][j-1][k-1] , dp[i][j][k]);
                    }
                }
            }
        }

        return max({dp[n-1][m-1][0] , dp[n-1][m-1][1] , dp[n-1][m-1][2]});
    }
};