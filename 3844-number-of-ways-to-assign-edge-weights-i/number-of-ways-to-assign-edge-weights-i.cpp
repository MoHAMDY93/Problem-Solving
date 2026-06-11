class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int MOD = 1e9 + 7;
        int n = edges.size() + 1;
        vector<vector<int>> memo(n+1 , vector<int> (2 , -1));
        auto dp = [&](this auto&& dp , int i , int rem) -> int {
            if (i == 0) return (int)(rem == 0);
            auto &ret = memo[i][rem];
            if (~ret) return ret;
            ret = (dp(i - 1, rem) + dp(i - 1, rem ^ 1)) % MOD;
            return ret;
        };
        dp(n , 0);
        dp(n , 1);
        // memo has all number of ways to get odd sum of edges wehighting 1 or 2 for mx (number of nodes)
        vector<vector<int>> adj(n+1);
        for (auto v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        auto dfs = [&](this auto&& dfs , int u , int p) -> int {
            int len = 0;
            for (auto v : adj[u]) {
                if (v == p) continue;
                len = max(len , 1 + dfs(v , u));  
            }
            return len;
        };
        int maxi = dfs(1 , 0);
        // cout << n << ' ' << maxi << ' ' << memo[1][1] << '\n';
        return memo[maxi][1];
    }
};