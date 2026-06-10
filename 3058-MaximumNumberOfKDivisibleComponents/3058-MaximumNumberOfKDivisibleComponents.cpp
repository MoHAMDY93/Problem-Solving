// Last updated: 6/10/2026, 7:14:59 PM
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            auto u = e[0] , v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> parent(n);
        vector<int> st;
        auto dfs = [&](int u , int p , auto &&dfs) -> void {
            parent[u] = p;
            st.push_back(u);
            for(auto v : adj[u]) {
                if(v == p) continue;
                dfs(v , u , dfs);
            }
        };
        dfs(0 , -1 , dfs);
        vector<long long> sum(n);
        for(int i=0 ; i<n ; i++) sum[i] = values[i];   
        int ans = 0;
        while(!st.empty()) {
            auto u = st.back(); st.pop_back();
            // cout << sum[u] << '\n';
            if(sum[u] % k == 0) ans++;
            else 
                sum[parent[u]] += sum[u];
        }
        return ans;
    }
};