// Last updated: 6/10/2026, 7:27:18 PM
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> a(m+1 , vector<int> (n+1 , 0));
        a[0][0] = 1;
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(i > 0) a[i][j] += a[i-1][j];
                if(j > 0) a[i][j] += a[i][j-1]; 
            }
        } 
        return a[m-1][n-1];
    }
};