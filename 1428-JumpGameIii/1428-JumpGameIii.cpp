// Last updated: 6/10/2026, 7:21:31 PM
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n , false);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (arr[u] == 0) return true;
            if (u + arr[u] < n && !vis[u + arr[u]]) q.push(u + arr[u]) , vis[u + arr[u]] = true;
            if (u - arr[u] >=0 && !vis[u - arr[u]]) q.push(u - arr[u]) , vis[u - arr[u]] = true;
        }
        return false;
    }
};