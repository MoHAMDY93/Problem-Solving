// Last updated: 6/11/2026, 4:24:56 AM
// Can be more easy using 2 ^ (maxi - 1)
1class Solution {
2public:
3    int assignEdgeWeights(vector<vector<int>>& edges) {
4        int MOD = 1e9 + 7;
5        int n = edges.size() + 1;
6        vector<vector<int>> memo(n+1 , vector<int> (2 , -1));
7        auto dp = [&](this auto&& dp , int i , int rem) -> int {
8            if (i == 0) return (int)(rem == 0);
9            auto &ret = memo[i][rem];
10            if (~ret) return ret;
11            ret = (dp(i - 1, rem) + dp(i - 1, rem ^ 1)) % MOD;
12            return ret;
13        };
14        dp(n , 0);
15        dp(n , 1);
16        // memo has all number of ways to get odd sum of edges wehighting 1 or 2 for mx (number of nodes)
17        vector<vector<int>> adj(n+1);
18        for (auto v : edges) {
19            adj[v[0]].push_back(v[1]);
20            adj[v[1]].push_back(v[0]);
21        }
22        auto dfs = [&](this auto&& dfs , int u , int p) -> int {
23            int len = 0;
24            for (auto v : adj[u]) {
25                if (v == p) continue;
26                len = max(len , 1 + dfs(v , u));  
27            }
28            return len;
29        };
30        int maxi = dfs(1 , 0);
31        // cout << n << ' ' << maxi << ' ' << memo[1][1] << '\n';
32        return memo[maxi][1];
33    }
34};