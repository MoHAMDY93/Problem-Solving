// Last updated: 8/5/2026, 3:57:05 AM
1class Solution {
2public:
3    vector<int> remainingMethods(int n, int k, vector<vector<int>>& edges) {
4        vector<bool> sus(n , 0);
5        vector<vector<int>> adj(n);
6        for (auto v : edges) {
7            adj[v[0]].push_back(v[1]);
8        }
9        auto dfs_sus = [&](this auto&& dfs_sus , int u) -> void {
10            sus[u] = 1;
11            for (auto v : adj[u]) {
12                if (sus[v]) continue;
13                dfs_sus(v);
14            }
15        };
16        dfs_sus(k);
17        // for (int u=0 ; u<n ; u++) cout << sus[u] << ' ';
18        // cout << '\n';
19        bool all = false;
20        vector<bool> vis(n , 0);
21        auto dfs = [&](this auto&& dfs , int u) -> void {
22            vis[u] = 1;
23            for (auto v : adj[u]) {
24                if (vis[v]) continue;
25                if (sus[v]) { all = true; return; }
26                dfs(v);
27            }
28        };
29        for (int u = 0 ; u<n ; u++) {
30            if (sus[u]) continue;
31            dfs(u);
32            if (all) {
33                vector<int> ans(n);
34                iota(begin(ans) , end(ans) , 0);
35                return ans;
36            }
37        }
38        vector<int> ans;
39        for (int u=0 ; u<n ; u++) if (!sus[u]) ans.push_back(u);
40        return ans;
41    }
42};