// Last updated: 6/10/2026, 7:22:14 PM
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> pref(mat.begin() , mat.end());
        for(int i=0 ; i<mat.size() ; i++) {
            for(int j=0 ; j<mat[0].size() ; j++) {
                if(i > 0) pref[i][j] += pref[i-1][j];
                if(j > 0) pref[i][j] += pref[i][j-1];
                if(i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
            }
        }
        auto rect_sum = [&](int u1, int v1, int u2, int v2) {
            long long res = pref[u2][v2];
            if(u1 > 0) res -= pref[u1-1][v2];
            if(v1 > 0) res -= pref[u2][v1-1];
            if(u1 > 0 && v1 > 0) res += pref[u1-1][v1-1];
            return res;
        };
        vector<vector<int>> ans(mat.size() , vector<int> (mat[0].size() , 0));
        for(int i=0 ; i<mat.size() ; i++) {
            for(int j=0 ; j<mat[0].size() ; j++) {
                int u1 = max(0 , i - k) , u2 = min((int)mat.size()-1 , i + k);
                int v1 = max(0 , j - k) , v2 = min((int)mat[0].size()-1 , j + k);
                
                ans[i][j] = rect_sum(u1 , v1 , u2 , v2);
            }
        }
        return ans;
    }
};