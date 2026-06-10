// Last updated: 6/10/2026, 7:27:07 PM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<bool> ROW(n , false) , COL(m , false);
        for(int r=0 ; r < n ; r++) {
            for(int c=0 ; c < m ; c++) {
                if(matrix[r][c] == 0) {
                    ROW[r] = true , COL[c] = true;
                }
            }
        }
        for(int r=0 ; r < n ; r++) {
            for(int c=0 ; c < m ; c++) {
                if(ROW[r] || COL[c]) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};