// Last updated: 8/1/2026, 11:19:49 PM
1class Solution {
2public:
3    bool predictTheWinner(vector<int>& nums) {
4        int n = nums.size();
5        vector<vector<long long>> memo(n , vector<long long> (n , -1));
6        auto dp = [&](this auto&& dp , int i , int j) -> long long {
7            if (i > j) return 0;
8            auto& ret = memo[i][j]; 
9            if (~ret) return ret;
10            ret = LLONG_MIN;
11            ret = max(ret , nums[i] - dp(i+1 , j));
12            ret = max(ret , nums[j] - dp(i , j-1));
13
14            return ret;
15        };
16        return dp(0 , n-1) >= 0 ? true : false;
17    }
18};