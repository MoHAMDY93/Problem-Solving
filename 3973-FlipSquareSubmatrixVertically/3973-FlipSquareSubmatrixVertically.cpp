// Last updated: 6/10/2026, 7:10:54 PM
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i=x , op = (x + k - 1) ; i<op ; i++ , op--) {
            cout << i << ' ' << op << '\n';
            for (int j=y ; j<y + k ; j++) {
                swap(grid[i][j] , grid[op][j]); 
            }
        }
        return grid;
    }
};