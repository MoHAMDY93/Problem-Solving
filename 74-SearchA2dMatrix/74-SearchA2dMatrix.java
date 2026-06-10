// Last updated: 6/10/2026, 7:27:06 PM
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = (matrix.length), m = (matrix[0].length);
        for(int i=0 ; i<n * m ; i++) {
            int r = i / m, c = i % m;
            if(matrix[r][c] > target) return false;
            if(matrix[r][c] == target) return true;
        }
        return false;
    }
}