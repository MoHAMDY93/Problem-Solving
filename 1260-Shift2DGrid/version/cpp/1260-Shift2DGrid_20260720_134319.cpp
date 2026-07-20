// Last updated: 7/20/2026, 1:43:19 PM
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int n = grid.size() , m = grid[0].size();
5        while (k--) {
6            for (int i=0 ; i<n ; i++) {
7                for (int j = m-1 ; j>0 ; j--) {
8                    swap(grid[i][j] , grid[i][j-1]);
9                }
10            }
11            for (int i=n-1 ; i>0 ; i--) swap(grid[i][0] , grid[i-1][0]);
12        }
13        return grid;
14    }
15};