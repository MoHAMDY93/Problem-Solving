class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> indeg(n , 0);
        for (auto e : edges) {
            adj[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }
        // for (auto i : indeg) cout << i << ' ';
        // cout << '\n';
        vector<int> ans;
        queue<int> q;
        for (int u=0 ; u<n ; u++) {
            if (indeg[u]) continue;
            q.push(u);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(u); 
            for (int v : adj[u]) {
                indeg[v]--;
                if (!indeg[v]) q.push(v);
            }
        }
        if (ans.size() != n) return {};
        return ans;
    }
};