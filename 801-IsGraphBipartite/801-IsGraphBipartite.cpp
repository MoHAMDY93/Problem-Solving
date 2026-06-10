// Last updated: 6/10/2026, 7:23:39 PM
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n , -1);
        bool ok = true;
        auto dfs = [&](this auto&& dfs , int u , int c) -> void {
            color[u] = c;
            for (auto v : graph[u]) {
                if (color[v] == -1) 
                    dfs(v , c ^ 1);
                else if (color[u] == color[v]) ok = false;
            }    
        };
        for (int u=0 ; u<n ; u++) {
            if (color[u] == -1) 
                dfs(u , 0);
        }
        return ok;
    }
};