// Last updated: 7/14/2026, 9:43:27 PM
1class Solution {
2public:
3    const int MOD = 1e9 + 7;
4    int subsequencePairCount(vector<int>& nums) {
5        int n = nums.size();
6        vector<vector<vector<int>>> memo(n , vector<vector<int>>(201 , vector<int>(201 , -1)));
7        auto dp = [&](this auto&& dp , int i , int gc1 , int gc2) -> int {
8            if (i == n) return (int)(gc1 == gc2 && gc1 != 0);
9            auto& ret = memo[i][gc1][gc2];
10            if (~ret) return ret;
11            ret = dp(i+1 , gc1 , gc2) % MOD;
12            long long op1 = dp(i+1 , gcd(gc1 , nums[i]) , gc2) % MOD;
13            long long op2 = dp(i+1 , gc1 , gcd(gc2 , nums[i])) % MOD;
14            ret = (ret + op1 + op2) % MOD;
15            return ret;
16        };
17        return dp(0 , 0 , 0);
18    }
19};