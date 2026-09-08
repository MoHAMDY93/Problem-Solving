class Solution {
public:
    int distinctSubseqII(string s) {
        long long last[26] = {};
        const int MOD = 1e9 + 7;
        for (char c : s) {
            last[c - 'a'] = accumulate(begin(last) , end(last) , 1LL) % MOD;
        }
        return accumulate(begin(last) , end(last) , 0LL) % MOD;
    }
};