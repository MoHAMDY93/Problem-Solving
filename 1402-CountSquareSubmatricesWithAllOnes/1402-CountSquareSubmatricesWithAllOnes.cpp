// Last updated: 6/10/2026, 7:21:41 PM
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size() , c = matrix[0].size();
        vector<vector<int>> grid(r+1 , vector<int> (c+1 , 0));
        int ans = 0;
        for(int i=0 ; i<r ; i++) {
            for(int j=0 ; j<c ; j++) {
                if(matrix[i][j] == 1) {
                    grid[i+1][j+1] = min({grid[i+1][j] , grid[i][j+1] , grid[i][j]}) + 1;
                    ans += grid[i+1][j+1];
                }                
            }
        } 
        return ans;      
    }
};