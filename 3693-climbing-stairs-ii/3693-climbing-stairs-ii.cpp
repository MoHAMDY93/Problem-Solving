class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> memo(n , -1);
        auto dp = [&](this auto&& dp, int i) -> int {
            if (i == n-1) return 0;
            
            auto& ret = memo[i];
            if (~ret) return ret;
            
            ret = costs[i+1] + 1 + dp(i+1);
            if (i+2 < n) ret = min(ret, 4 + costs[i+2] + dp(i+2));
            if (i+3 < n) ret = min(ret, 9 + costs[i+3] + dp(i+3));

            return ret;
        };
        int ans = 1 + costs[0] + dp(0);
        if (1 < n) ans = min(ans, 4 + costs[1] + dp(1));
        if (2 < n) ans = min(ans, 9 + costs[2] + dp(2));
        return ans;
    }
};