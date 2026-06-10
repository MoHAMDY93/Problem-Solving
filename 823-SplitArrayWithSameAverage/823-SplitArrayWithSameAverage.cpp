// Last updated: 6/10/2026, 7:23:29 PM
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int S = accumulate(nums.begin(), nums.end(), 0);

        // dp[k] = set of all possible sums using k elements
        vector<unordered_set<int>> dp(n + 1);
        dp[0].insert(0);

        for (int x : nums) {
            for (int k = n - 1; k >= 0; k--) {
                for (int s : dp[k]) {
                    dp[k + 1].insert(s + x);
                }
            }
        }

        for (int k = 1; k <= n / 2; k++) {
            if ((S * k) % n != 0) continue;

            int target = (S * k) / n;
            if (dp[k].count(target)) return true;
        }

        return false;
    }
};