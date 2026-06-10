// Last updated: 6/10/2026, 7:11:57 PM
class Solution {
public:
    int numberOfComponents(vector<vector<int>>& props, int k) {
        vector<vector<int>> adj;
        int n = props.size();
        adj.assign(n+1 , {});
        for(int i = 0; i < n; i++) sort(props[i].begin(), props[i].end());
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                vector<int> inter;
                set_intersection(props[i].begin(), props[i].end(),
                                props[j].begin(), props[j].end(),
                                back_inserter(inter));
                unordered_set<int> interSt(inter.begin() , inter.end());
                // for(auto i : ) cout << i << ' ';
                cout << '\n';
                if(interSt.size() >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(auto v : adj) {
            for(auto i : v) cout << i << ' ';
            cout << '\n';
        }
        vector<bool> vis(n+1 , false);
        int cnt = 0;
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
                            q.push(v);
                            vis[v] = 1;
                        }
                    }
                }
            }
        } 
        return cnt;
    }
};