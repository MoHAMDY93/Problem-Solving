class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        long long dp = 1;
        int last[128] = {};
        for (auto c : s) {
            int new_dp = (dp * 2 - last[c] + MOD) % MOD;
            last[c] = dp;
            dp = new_dp;
        }
        return (dp - 1 + MOD) % MOD;
    }
};