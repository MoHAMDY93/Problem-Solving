// Last updated: 6/10/2026, 7:11:19 PM
using ll = long long;
class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        // BFS + PQ
        vector<vector<bool>> vis(m , vector<bool>(n , false));
        priority_queue<pair<ll , pair<ll , ll>> , vector<pair<ll , pair<ll , ll>>> , 
        greater<pair<ll , pair<ll , ll>>>> pq;
        pq.push({1 , {0 , 0}});
        vis[0][0] = true;;
        while(!pq.empty()) {
            auto [curr , pos] = pq.top(); pq.pop();
            auto [x , y] = pos;
            if(x == m-1 && y == n-1) return curr - waitCost[x][y];
            if(x+1 < m && !vis[x+1][y]) pq.push({curr + ((x+2) * (y+1)) + waitCost[x+1][y] , {x+1 , y}}) , vis[x+1][y] = true;
            if(y+1 < n && !vis[x][y+1]) pq.push({curr + ((x+1) * (y+2)) + waitCost[x][y+1] , {x , y+1}}) , vis[x][y+1] = true;
        }
        return 0;
    }
};