// Last updated: 6/10/2026, 7:14:09 PM
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size() , m = grid[0].size();
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (i > 0 && j > 0) grid[i][j] = grid[i][j] + grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]; 
                else if (i > 0) grid[i][j] += grid[i-1][j]; 
                else if (j > 0) grid[i][j] += grid[i][j-1];

                ans += (grid[i][j] <= k); 
            }
        }
        return ans;
    }
};