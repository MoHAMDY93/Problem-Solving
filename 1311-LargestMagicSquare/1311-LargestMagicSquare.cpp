// Last updated: 6/10/2026, 7:21:57 PM
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                for(int k=1 ; k<min(n-i , m-j) ; k++) {
                    int target = 0;
                    for(int d = 0; d <= k; d++)
                        target += grid[i][j + d]; // first row

                    bool ok = true;

                    // rows
                    for(int r = 0; r <= k && ok; r++) {
                        int s = 0;
                        for(int c = 0; c <= k; c++)
                            s += grid[i + r][j + c];
                        if(s != target) ok = false;
                    }

                    // columns
                    for(int c = 0; c <= k && ok; c++) {
                        int s = 0;
                        for(int r = 0; r <= k; r++)
                            s += grid[i + r][j + c];
                        if(s != target) ok = false;
                    }

                    // main diagonal
                    int d1 = 0, d2 = 0;
                    for(int d = 0; d <= k; d++) {
                        d1 += grid[i + d][j + d];
                        d2 += grid[i + d][j + k - d];
                    }

                    if(d1 != target || d2 != target) ok = false;

                    if(ok) ans = max(ans, k + 1);
                }
            }
        }
        return ans;
    }
};