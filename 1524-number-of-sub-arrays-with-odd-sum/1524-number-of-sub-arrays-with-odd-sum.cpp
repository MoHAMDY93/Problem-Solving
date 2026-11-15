class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<vector<int>> memo(n, vector<int> (2, -1));
        auto dp = [&](this auto&& dp, int i, int parity) -> int {
            if (i == n) return parity == 1;
            auto& ret = memo[i][parity];
            if (~ret) return ret;
            ret = (dp(i+1, (parity + arr[i]) % 2) + dp(n, parity)) % mod;
            return ret;
        };
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            ans = (ans + dp(i , 0) % mod) % mod;
        }
        return ans;
    }
};