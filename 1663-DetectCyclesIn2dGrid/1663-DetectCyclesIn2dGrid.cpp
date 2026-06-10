// Last updated: 6/10/2026, 7:20:29 PM
class Solution {
public:
    int n , m;
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size() , m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool> (m , false));
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (vis[i][j]) continue;
                if (dfs(grid , vis , i , j , -1 , -1)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& grid , vector<vector<bool>>& vis , int cx , int cy , int px , int py) {
        int dx[] = {1 , -1 , 0 , 0};
        int dy[] = {0 , 0 , 1 , -1};
        vis[cx][cy] = 1;
        for (int d=0 ; d<4 ; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (grid[nx][ny] != grid[cx][cy] || (nx == px && ny == py)) continue;
                if (vis[nx][ny]) return true;
                if (dfs(grid , vis , nx , ny , cx , cy))
                    return true;
            }
        }
        return false;
    }
};