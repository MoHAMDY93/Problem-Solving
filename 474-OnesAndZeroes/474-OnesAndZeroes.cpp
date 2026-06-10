// Last updated: 6/10/2026, 7:24:46 PM
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
        for(string s : strs) {
            int zs = 0 , os = 0;
            for(auto c : s) {
                zs += (c == '0');
                os += (c == '1');
            }
            for(int i=m ; i>=zs ; i--) {
                for(int j=n ; j>=os ; j--) {
                    dp[i][j] = max(dp[i][j] , dp[i-zs][j-os] + 1);
                }
            }
        }
        return dp[m][n];
    }
};