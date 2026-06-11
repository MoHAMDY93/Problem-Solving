// Last updated: 6/11/2026, 5:22:42 AM
// Finally got my first LCA problem on LeetCode, cheers
1struct TreeAncestor {
2    int n, max_power;
3    const vector<vector<int>>& adj; // Reference to the external adjacency list
4    vector<vector<int>> anc;
5    vector<int> depth;
6
7    // Constructor accepting the adjacency list by reference
8    TreeAncestor(int n_nodes, const vector<vector<int>>& external_adj) : adj(external_adj) {
9        n = n_nodes;
10        max_power = 31 - __builtin_clz(n) + 1;
11        anc.assign(n, vector<int>(max_power, 0));
12        depth.assign(n, 0);
13    }
14
15    // DFS to establish depths and immediate parents
16    void dfs(int u, int p) {
17        for (auto v : adj[u]) {
18            if (v == p) continue;
19            anc[v][0] = u;
20            depth[v] = depth[u] + 1;
21            dfs(v, u);
22        }
23    }
24
25    // Build the binary lifting table iteratively
26    void build(int root = 0) {
27        anc[root][0] = root; // Root points to itself
28        depth[root] = 0;
29        
30        dfs(root, -1);
31
32        // Iterative DP step to fill up powers of 2
33        for (int j = 1; j < max_power; j++) {
34            for (int i = 0; i < n; i++) {
35                anc[i][j] = anc[anc[i][j - 1]][j - 1];
36            }
37        }
38    }
39
40    // Query the k-th ancestor (0-indexed logic)
41    int get_kth_ancestor(int u, int k) {
42        if (k > depth[u]) return -1;
43        for (int i = 0; i < max_power; i++) {
44            if ((k >> i) & 1) {
45                u = anc[u][i];
46            }
47        }
48        return u;
49    }
50
51    // Query the LCA between u & v
52    int LCA(int u , int v) {
53        if (depth[u] < depth[v])
54            swap(u , v);
55        
56        int diff = depth[u] - depth[v];
57        u = get_kth_ancestor(u , diff);
58        if (u == v) return u;
59        for (int i = max_power-1 ; i >= 0 ; i--) {
60            if (anc[u][i] != anc[v][i]) {
61                u = anc[u][i];
62                v = anc[v][i];
63            }
64        }
65        return anc[u][0];
66    }
67    
68    int get_kth_node_on_path(int s, int t, int k) {
69        int lca = LCA(s, t);
70        int dist_s = depth[s] - depth[lca];
71        int dist_t = depth[t] - depth[lca];
72        
73        // Total number of edges on the path from s to t
74        int total_dist = dist_s + dist_t; 
75        
76        // If k is out of bounds
77        if (k < 0 || k > total_dist) return -1; 
78        
79        // If the target node lies on the ascending chain (s -> LCA)
80        if (k <= dist_s) {
81            return get_kth_ancestor(s, k);
82        } 
83        // If the target node lies on the descending chain (LCA -> t)
84        else {
85            int k_from_t = total_dist - k;
86            return get_kth_ancestor(t, k_from_t);
87        }
88    }
89    int dist(int u , int v) {
90        int lca = LCA(u , v);
91        return depth[u] + depth[v] - 2 * depth[lca];
92    }
93};
94
95class Solution {
96private:
97    int MOD = 1e9+7;
98    int bin_pow(int exp) {
99        long long res = 1 , base = 2;
100        while (exp) {
101            if (exp & 1) res = (res * base) % MOD;
102            base = (base * base) % MOD;
103            exp >>= 1;
104        }
105        return res;
106    }
107public:
108    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
109        int n = edges.size() + 1;
110        vector<vector<int>> adj(n);
111        for (auto e : edges) {
112            int u = e[0] - 1 , v = e[1] - 1;
113            adj[u].push_back(v);
114            adj[v].push_back(u);
115        }
116        TreeAncestor tree(n , adj);
117        tree.build(0);
118        vector<int> ans;
119        for (auto q : queries) {
120            int u = q[0]-1 , v = q[1]-1;
121            int len = tree.dist(u , v);
122            // cout << len << '\n';
123            if (!len) ans.push_back(0);
124            else ans.push_back(bin_pow(len - 1));
125        }
126        return ans;
127    }
128};