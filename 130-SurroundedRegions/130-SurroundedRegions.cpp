// Last updated: 6/10/2026, 7:26:34 PM
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m , false));
        
        auto dfs = [&](int i , int j ,auto&& dfs) {
            int dx[] = {0 , 0 , 1 , -1};
            int dy[] = {1 , -1 , 0 , 0};
            if(0 > i || i >= n || 0 > j || j >= m || board[i][j] == 'X' || vis[i][j]) return;
            vis[i][j] = true;
            for(int d=0 ; d<4 ; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                dfs(ni , nj , dfs);
            }
        };
        
        for(int j=0 ; j<m ; j++) {
            if(!vis[0][j] && board[0][j] == 'O') {
                dfs(0 , j , dfs);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1 , j , dfs);
            }
        }
        for(int i=0 ; i<n ; i++) {
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i , 0 , dfs);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i , m-1 , dfs);
            }
        }

        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(vis[i][j]) board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};