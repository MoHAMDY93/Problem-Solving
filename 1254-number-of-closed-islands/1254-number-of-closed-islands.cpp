class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        /*
            for each not visisted 0 we start dfs to get all connected 0s, but if we are directly connected to any edge so this component contributs with nothing 
        */
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool> (m , false));
        int dx[] = {1 , -1 , 0 , 0};
        int dy[] = {0 , 0 , 1 , -1};
        int ans = 0;
        for (int x=0 ; x<n ; x++) {
            for (int y=0 ; y<m ; y++) {
                if (vis[x][y] || grid[x][y] == 1) continue;
                queue<pair<int , int>> q;
                q.push({x , y});
                vis[x][y] = 1;
                bool ok = true;
                while (!q.empty()) {
                    auto [xx , yy] = q.front(); q.pop();
                    for (int d=0 ; d<4 ; d++) {
                        int nx = xx + dx[d] , ny = yy + dy[d];
                        if (0 > nx || nx >= n || 0 > ny || ny >= m) ok = false;
                        else if (!vis[nx][ny] && grid[nx][ny] == 0) {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                ans += ok;
            }
        }
        return ans;
    }
};