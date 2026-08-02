// Last updated: 8/2/2026, 10:13:50 AM
1class Solution {
2public:
3    bool stoneGame(vector<int>& piles) {
4        int n = piles.size();
5        vector<vector<int>> memo(n , vector<int> (n , -1));
6        auto dp = [&](this auto&& dp , int i , int j) -> int {
7            if (i > j) return 0;
8            auto& ret = memo[i][j];
9            if (~ret) return ret;
10            
11            ret = INT_MIN;
12            ret = max({ret , piles[i] - dp(i+1 , j) , piles[j] - dp(i , j-1)});
13
14            return ret; 
15        };
16        return dp(0 , n-1) >= 0 ? true : false;
17    }
18};