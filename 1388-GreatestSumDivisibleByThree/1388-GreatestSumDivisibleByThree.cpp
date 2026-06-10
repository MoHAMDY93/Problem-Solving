// Last updated: 6/10/2026, 7:21:46 PM
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n , vector<int>(3 , -1));
        function<int(int , int)> dp = [&](int i , int r) {
            if(i == n) return (r == 0) ? 0 : INT_MIN;
            auto &ret = memo[i][r];
            if(~ret) return ret;
            ret = dp(i+1 , r);
            ret = max(ret , nums[i] + dp(i+1 , (r + (nums[i] % 3)) % 3));
            return ret;
        };
        return dp(0 , 0);
    }
};