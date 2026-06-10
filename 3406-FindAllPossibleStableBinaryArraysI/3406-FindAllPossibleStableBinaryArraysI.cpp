// Last updated: 6/10/2026, 7:13:56 PM
class Solution {
    const long long MOD = 1e9 + 7;
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int dp[zero + 1][one + 1][2];
        memset(dp, 0, sizeof(dp));
        
        for (int i = min(zero, limit); i >= 0; i--)
            dp[i][0][0] = 1;
        for (int j = min(one, limit); j >= 0; j--)
            dp[0][j][1] = 1;

        for (int z=1 ; z <= zero ; z++) {
            for (int o=1 ; o <= one ; o++) {
                dp[z][o][0] = (0LL + dp[z-1][o][0] + dp[z-1][o][1] - (z - limit - 1 >= 0 ? dp[z - 1 - limit][o][1] : 0LL) + MOD) % MOD;
                dp[z][o][1] = (0LL + dp[z][o-1][0] + dp[z][o-1][1] - (o - limit - 1 >= 0 ? dp[z][o - limit - 1][0] : 0LL) + MOD) % MOD;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};