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
        auto dfs = [&](this auto&& dfs , int x , int y) -> bool {
            if (0 > x || x >= n || 0 > y || y >= m) return false;
            if (grid[x][y] == 1 || vis[x][y]) return true;
            vis[x][y] = true;
            bool ok = true;
            for (int d=0 ; d<4 ; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                ok &= dfs(nx , ny);
            }
            return ok;
        };
        int ans = 0;
        for (int x=0 ; x<n ; x++) {
            for (int y=0 ; y<m ; y++) {
                if (vis[x][y] || grid[x][y] == 1) continue;
                ans += dfs(x , y);
            }
        }
        return ans;
    }
};