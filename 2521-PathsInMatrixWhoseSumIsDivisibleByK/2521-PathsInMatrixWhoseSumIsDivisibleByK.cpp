// Last updated: 6/10/2026, 7:16:41 PM
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int MOD = (int)(1e9 + 7);
        int n = grid.size() , m = grid[0].size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(m , vector<int>(k , 0)));
        dp[0][0][grid[0][0] % k] = 1;
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                for(int x=0 ; x<k ; x++) {
                    int rn = (x + grid[i][j]) % k;
                    if(i > 0) dp[i][j][rn] = (dp[i][j][rn] + dp[i-1][j][x]) % MOD;
                    if(j > 0) dp[i][j][rn] = (dp[i][j][rn] + dp[i][j-1][x]) % MOD;
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};