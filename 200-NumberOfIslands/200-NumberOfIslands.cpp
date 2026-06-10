// Last updated: 6/10/2026, 7:25:57 PM
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        function<void(int , int)> bfs = [&](int x , int y) {
            queue<pair<int , int>> q;
            q.push({x , y});
            grid[x][y] = '0';
            int dx[] = {1 , -1 , 0 , 0};
            int dy[] = {0 , 0 , 1 , -1};
            while(!q.empty()) {
                auto [x , y] = q.front(); q.pop();
                cout << x << ' ' << y << "\n";
                for(int i=0 ; i<4 ; i++) {
                    int nx = x + dx[i] , ny = y + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1') {
                        q.push({nx , ny});
                        grid[nx][ny] = '0';
                    }
                } 
            }   
        };
        int res = 0;
        // bfs(0 , 0);
        // for(int i=0 ; i<n ; i++) {
        //     for(int j=0 ; j<m ; j++)
        //         cout << grid[i][j] << ' ';
        //     cout << '\n';
        // }
        for(int i=0 ; i<n; i++) {
            for(int j=0 ; j<m ; j++) {
                if(grid[i][j] == '1') {
                    // cout << i << ' ' << j << "\n";
                    ++res;
                    bfs(i , j);
                }
            }
        }
        return res;
    }
};