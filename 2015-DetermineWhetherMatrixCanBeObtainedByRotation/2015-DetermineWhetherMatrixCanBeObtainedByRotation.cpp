// Last updated: 6/10/2026, 7:19:10 PM
class Solution {
public:
    void rotate90(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i=0 ; i<4 ; i++) {
            if (mat == target) return true;
            rotate90(mat);
        }   
        return false;
    }
};