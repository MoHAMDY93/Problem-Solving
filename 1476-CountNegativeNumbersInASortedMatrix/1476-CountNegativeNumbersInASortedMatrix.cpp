// Last updated: 6/10/2026, 7:21:13 PM
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i=0 ; i<grid.size() ; i++) {
            for(int j=0 ; j<grid[0].size() ; j++) {
                if(grid[i][j] < 0) {
                    cnt += grid[0].size() - j;
                    break;
                }
                // cnt += grid[i][j] < 0;
            }
        }
        return cnt;
    }
};