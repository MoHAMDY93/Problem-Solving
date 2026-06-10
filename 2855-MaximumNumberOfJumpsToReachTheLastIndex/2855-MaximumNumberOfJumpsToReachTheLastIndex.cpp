// Last updated: 6/10/2026, 7:15:26 PM
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> memo(n , -1);
        function<int(int)> dp = [&](int i) -> int {
            if (i == n-1) return 0;
            auto& ret = memo[i];
            if (~ret) return ret;
            ret = INT_MIN;
            for (int j = i+1 ; j<n ; j++) {
                if (abs(nums[i] - nums[j]) <= target) ret = max(ret , dp(j) + 1);
            }
            return ret;
        };
        int ans = dp(0);
        return ans <= INT_MIN / 2 ? -1 : ans;
    }
};