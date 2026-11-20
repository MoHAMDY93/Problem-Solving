class Solution {
public:
    int maxProfit(int k, vector<int>& nums) {
        int n = nums.size();
        int memo[n][2][k];
        auto dp = [&](this auto&& dp, int i, int sign, int cnt) -> int {
            if (i == n || cnt == k) return 0;
            auto& ret = memo[i][sign][cnt];
            if (~ret) return ret;
            int profit = (sign ? nums[i] : -nums[i]);
            ret = max(dp(i+1, sign, cnt), profit + dp(i+1, sign ^ 1, cnt + sign));
            return ret;
        };
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, 0);    
    }
};