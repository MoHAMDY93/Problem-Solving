// Last updated: 6/10/2026, 7:25:19 PM
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n , vector<int> (n+1 , -1));
        function<int(int , int)> dp = [&](int i , int prev) {
            if(i == n) return 0;
            auto &ret = memo[i][prev];
            if(~ret) return ret;
            int pr = prev-1;
            // skip
            ret = dp(i+1 , prev);
            // take
            if(pr == -1 || nums[i] > nums[pr]) ret = max(ret , 1 + dp(i+1 , i+1));
            return ret;
        };
        return dp(0 , 0);
    }
};