// Last updated: 6/10/2026, 7:22:48 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int INF = 1e9;
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dist(n , vector<int> (m , INF));
        queue<tuple<int , int , int>> q;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (grid[i][j] == 2) q.push({0 , i , j}) , dist[i][j] = 0;
            }
        }
        int dx[] = {1 , -1 , 0 , 0};
        int dy[] = {0 , 0 , 1 , -1};
        int ans = 0;
        while (!q.empty()) {
            auto [d , x , y] = q.front(); q.pop();
            for (int k=0 ; k<4 ; k++) {
                int nx = x + dx[k] , ny = y + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] == 1 &&  dist[nx][ny] > d + 1) { 
                    ans = max(ans , d+1);
                    dist[nx][ny] = d+1;
                    q.push({d+1 , nx , ny});
                }
            }
        }
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (grid[i][j] == 1 && dist[i][j] == INF) return -1;
            }
        }
        return ans;
    }
};