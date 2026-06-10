// Last updated: 6/10/2026, 7:20:22 PM
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        int ans = 0;
        vector<int> row_cnt(n , 0) , col_cnt(m , 0);
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                row_cnt[i] += mat[i][j] == 1;
                col_cnt[j] += mat[i][j] == 1;
            }
        }
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (mat[i][j] == 1 && row_cnt[i] == 1 && col_cnt[j] == 1) ans++;
            }
        }
        return ans;
    }
};