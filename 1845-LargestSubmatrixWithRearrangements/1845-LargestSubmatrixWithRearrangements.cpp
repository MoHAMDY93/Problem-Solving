// Last updated: 6/10/2026, 7:19:42 PM
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        for (int i=1 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (mat[i][j] == 1)
                    mat[i][j] += mat[i-1][j];
            }
        }
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            sort(mat[i].rbegin() , mat[i].rend());
            for (int j=0 ; j<m ; j++) {
                ans = max(ans , mat[i][j] * (j+1));
            }
        }
        return ans;
    }
};