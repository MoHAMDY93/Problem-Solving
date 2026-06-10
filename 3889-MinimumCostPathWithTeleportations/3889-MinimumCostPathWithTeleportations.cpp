// Last updated: 6/10/2026, 7:11:26 PM
class Solution {
public:
    const int INF = 1e9;
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, INF)));

        vector<array<int, 3>> cells;
        for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cells.push_back({grid[i][j], i, j});
        sort(cells.rbegin(), cells.rend());

        dp[0][0][0] = 0;
        for(int _k=0; _k <= k; ++_k) {

            if(_k > 0) {
                int p = 0, mn_cst = INF;
                while(p < n*m) {
                    auto [val, x, y] = cells[p];
                    int s = p;
                    while(p < n*m and cells[p][0] == val) {
                        mn_cst = min(mn_cst, dp[cells[p][1]][cells[p][2]][_k-1]);
                        p++;
                    }
                    for(int i=s; i<p; ++i) dp[cells[i][1]][cells[i][2]][_k] = min(dp[cells[i][1]][cells[i][2]][_k], mn_cst);
                }
            }

            for(int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j) {
                    if(i == 0 and j == 0) continue;
                    // I don't use teleport and go down
                    if(i-1 >= 0 and dp[i-1][j][_k] != INF) dp[i][j][_k] = min(dp[i][j][_k], dp[i-1][j][_k] + grid[i][j]);
                    // I don't use teleport and go right
                    if(j-1 >= 0 and dp[i][j-1][_k] != INF) dp[i][j][_k] = min(dp[i][j][_k], dp[i][j-1][_k] + grid[i][j]);
                }
            }
            // I use teleport.
            // 0, 0 -> i, j
            // TODO : for all cells with grid[x][y] >= current(grid[i][j])
            // iterate over _k = 0 to k-1 dp[i][j][_k+1] = min(dp[i][j][_k+1], dp[x][y][_k]);   
        }   
        // int ans = INF;
        // for(int _k=0; _k<=k; ++_k) ans = min(ans, dp[n-1][m-1][_k]);
        // return ans;
        return dp[n-1][m-1][k];
    }
};