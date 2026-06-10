// Last updated: 6/10/2026, 7:11:37 PM
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& conns, vector<vector<int>>& qs) {
        vector<vector<int>> adj(c);
        vector<bool> vis(c, false);
        vector<bool> off(c, false);
        vector<int> comp(c, -1);

        for (auto& e : conns) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int compID = 0;

        function<void(int, int)> dfs = [&](int u, int cid) {
            vis[u] = true;
            comp[u] = cid;
            for (int v : adj[u]) {
                if (!vis[v])
                    dfs(v, cid);
            }
        };

        for (int i = 0; i < c; i++) {
            if (!vis[i]) {
                dfs(i, compID);
                compID++;
            }
        }

        vector<set<int>> compMin(compID);
        for (int i = 0; i < c; i++) {
            compMin[comp[i]].insert(i);
        }

        vector<int> ans;

        for (auto& q : qs) {
            int idx = q[1] - 1;

            if (q[0] == 2) {
                off[idx] = true;
            } else {
                if(!off[idx]) ans.push_back(idx+1);
                else {
                    int cid = comp[idx];
                    while (!compMin[cid].empty() && off[*compMin[cid].begin()])
                        compMin[cid].erase(compMin[cid].begin());

                    if (!compMin[cid].empty())
                        ans.push_back(*compMin[cid].begin() + 1);
                    else
                        ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};
