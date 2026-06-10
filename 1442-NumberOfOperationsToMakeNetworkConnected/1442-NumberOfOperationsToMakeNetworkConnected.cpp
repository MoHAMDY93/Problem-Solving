// Last updated: 6/10/2026, 7:21:26 PM
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size() < n-1) return -1;
        int cnt = 0;
        vector<vector<int>> adj;
        adj.assign(n+1 , {});
        for(auto v : conn) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> vis(n+1 , false);
        for(int i=0 ; i<n ; i++) {
            if(!vis[i]) {
                cnt++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()) {
                    auto u = q.front(); q.pop();
                    for(auto v : adj[u]) {
                        if(!vis[v]) {
                            vis[v] = 1;
                            q.push(v);
                        }
                    }
                }
            }
        }
        return cnt - 1;
    }
};