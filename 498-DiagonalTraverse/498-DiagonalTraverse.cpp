// Last updated: 6/10/2026, 7:24:41 PM
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int n = mat.size() , m = mat[0].size();
        int x = 0 , y = 0 , dir = 1;
        while(true) {
            res.push_back(mat[x][y]);
            if(x == n-1 && y == m-1) break;
            if(dir) {
                x-- , y++;
                if(x < 0 || y >= m) {
                    dir = 0 , x++ , y--;
                    if(y < m-1) y++;
                    else x++;
                }
            } else {
                x++ , y--;
                if(x >= n || y < 0) {
                    dir = 1 , x-- , y++;
                    if(x < n-1) x++;
                    else y++;
                }
            }
            cout << x << ' ' << y << "\n";
        }
        return res;
    }
};