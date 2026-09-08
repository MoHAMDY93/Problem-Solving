class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long> last(128 , 0);
        const int MOD = 1e9 + 7;
        for (char c : s) {
            last[c] = accumulate(begin(last) , end(last) , 1LL) % MOD;
        } 
        return accumulate(begin(last) , end(last) , 0LL) % MOD;
    }
};