// Last updated: 8/3/2026, 11:16:08 PM
1class Solution {
2public:
3    string stoneGameIII(vector<int>& a) {
4        int n = a.size();
5        vector<int> memo(n , -1);
6        auto dp = [&](this auto&& dp , int i) -> int {
7            if (i >= n) return 0;
8            auto& ret = memo[i];
9            if (~ret) return ret;
10            ret = INT_MIN;
11            int sum = 0;
12            for (int j=0 ; j<3 && i + j < n ; j++) {
13                sum += a[i + j];
14                ret = max(ret , sum - dp(i + j + 1));
15            }
16
17            return ret;
18        };
19        auto best = dp(0);
20        if (best > 0) return "Alice";
21        if (best == 0) return "Tie";
22        return "Bob";
23    }
24};