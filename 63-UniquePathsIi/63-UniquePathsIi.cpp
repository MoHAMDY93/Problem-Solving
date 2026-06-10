// Last updated: 6/10/2026, 7:27:17 PM
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<long long>> dp(n , vector<long long>(m , 0));
        dp[0][0] = grid[0][0] == 0;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (grid[i][j] == 1) continue;
                if (i - 1 >= 0) dp[i][j] += dp[i-1][j]; 
                if (j - 1 >= 0) dp[i][j] += dp[i][j-1]; 
            }
        }
        return dp[n-1][m-1];
    }
};