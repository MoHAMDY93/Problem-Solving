// Last updated: 6/10/2026, 7:08:22 PM
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        long long dp[n+1][m+1][k+1], negINF = -1e15;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                for(int l = 0; l <= k; l++){
                    dp[i][j][l] = negINF;
                }
            }
        }

        // base case
        for(int j = 0; j <= m; j++) dp[n][j][0] = 0;
        for(int i = 0; i <= n; i++) dp[i][m][0] = 0;

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                for(int pair = 0; pair <= k; pair++){
                    if(pair)
                        dp[i][j][pair] = 1LL * nums1[i] * nums2[j] + dp[i+1][j+1][pair-1];  
                    dp[i][j][pair] = max({
                        dp[i][j][pair],
                        dp[i+1][j+1][pair],
                        dp[i+1][j][pair],  
                        dp[i][j+1][pair],  
                    });
                }
            }
        }
        
        return dp[0][0][k];
    }
};