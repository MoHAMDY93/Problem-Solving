// Last updated: 6/10/2026, 7:25:02 PM
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1 , -1);
        function<int(int)> count = [&](int curr) {
            if(curr > target) return 0;
            if(curr == target) return 1;
            if(dp[curr] != -1) return dp[curr];
            int ways = 0;
            for(int i : nums) {
                ways += count(curr + i);
            }
            return dp[curr] = ways;
        };
        return count(0);
    }
};