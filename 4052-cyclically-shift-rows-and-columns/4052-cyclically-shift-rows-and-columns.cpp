class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> ans(n , vector<int> (n));
        for (int i=0 ; i<n ; i++) {
            for (int j = rowShift[i] % n , step = 0; step < n ; step++ , j = (j + 1) % n)
                ans[i][step] = grid[i][j];
        }
        grid = ans;
        for (int j=0 ; j<n ; j++) {
            for (int i = colShift[j] % n , step = 0; step < n ; step++ , i = (i + 1) % n)
                ans[step][j] = grid[i][j];
        }
        return ans;
    }
};