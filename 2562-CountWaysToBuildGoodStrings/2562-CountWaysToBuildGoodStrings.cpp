// Last updated: 6/10/2026, 7:16:23 PM
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<int> memo(high+1 , -1);
        auto dp = [&](this auto&& dp , int i) -> int {
            if (i > high) return 0;
            auto & ret = memo[i];
            if (~ret) return ret;
            
            int cost0 = (i + zero >= low && i + zero <= high);
            int cost1 = (i + one >= low && i + one <= high);
            ret = (dp(i + zero) + cost0 + dp(i + one) + cost1) % MOD;

            return ret;
        };

        return dp(0);
    }
};