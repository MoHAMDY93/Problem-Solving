// Last updated: 6/10/2026, 7:23:06 PM
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        for (int i=1 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                int best = mat[i-1][j];
                if (j-1 >= 0) best = min(best , mat[i-1][j-1]);
                if (j+1 < n) best = min(best , mat[i-1][j+1]);
                mat[i][j] += best;
            }
        }
        return *min_element(mat[n-1].begin() , mat[n-1].end());
    }
};