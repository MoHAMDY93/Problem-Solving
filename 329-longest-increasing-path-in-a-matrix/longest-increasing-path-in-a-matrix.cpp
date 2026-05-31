class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>> memo(n , vector<int>(m , -1));
        int dx[] = {-1 , 1 , 0 , 0};
        int dy[] = {0 , 0 , -1 , 1};
        auto dfs = [&](this auto&& dfs , int x , int y) -> int {
            if (~memo[x][y]) return memo[x][y];
            int best = 1;
            for (int d=0 ; d<4 ; d++) {
                int nx = x + dx[d] , ny = y + dy[d];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && matrix[nx][ny] > matrix[x][y])
                    best = max(best , 1 + dfs(nx , ny));
            }
            return memo[x][y] = best;
        };
        int ans = 0;
        for (int i=0 ; i<n ; i++) 
            for (int j=0 ; j<m ; j++)
                ans = max(ans , dfs(i , j));
        return ans;
    }
};