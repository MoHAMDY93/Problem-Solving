// Last updated: 7/4/2026, 8:35:22 PM
1class Solution {
2public:
3    int minScore(int n, vector<vector<int>>& roads) {
4        vector<vector<pair<int , int>>> adj(n+1);
5        for (auto e : roads) {
6            int u = e[0] , v = e[1] , w = e[2];
7            adj[u].push_back({v , w});
8            adj[v].push_back({u , w});
9        }
10        int mn = INT_MAX;
11        vector<bool> vis(n + 1, false);
12        auto dfs = [&](this auto&& dfs, int u) -> void {
13            vis[u] = true;
14            for (auto [v, w] : adj[u]) {
15                mn = min(mn, w);        
16                if (!vis[v]) {
17                    dfs(v);
18                }
19            }
20        };
21        dfs(n);
22        return mn;
23    }
24};