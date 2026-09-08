class Solution {
public:
    int distinctSubseqII(string s) {
        long long dp = 1 , MOD = 1e9 + 7;
        int last[26] = {};
        for (char c : s) {
            int new_dp = (dp * 2 - last[c - 'a'] + MOD) % MOD;
            last[c - 'a'] = dp;
            dp = new_dp;
        }
        return (dp - 1 + MOD) % MOD;
    }
};