// Last updated: 6/10/2026, 7:21:23 PM
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int , set<int>> mp;
        for (int i=0 ; i<n ; i++) mp[arr[i]].insert(i);
        vector<bool> vis(n , false);
        unordered_set<int> st;
        // vector<bool> vis_group(n , false);
        queue<pair<int , int>> q;
        q.push({0 , 0});
        while (!q.empty()) {
            auto [u , dist] = q.front(); q.pop();
            if (u == n-1) return dist;
            if (!st.count(arr[u])) {
                for (auto v : mp[arr[u]]) {
                    if (vis[v]) continue;
                    q.push({v , dist+1});
                    vis[v] = 1;
                }
                st.insert(arr[u]);
            }
            if (u + 1 < n && !vis[u+1]) vis[u+1] = 1 , q.push({u+1 , dist+1});
            if (u - 1 >=0 && !vis[u-1]) vis[u-1] = 1 , q.push({u-1 , dist+1});
        }
        return -1;
    }
};