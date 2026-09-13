class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int , int>> ones_1 , ones_2;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (img1[i][j] == 1) ones_1.emplace_back(i , j);
                if (img2[i][j] == 1) ones_2.emplace_back(i , j);
            }
        }
        vector<vector<int>> shift(2 * n, vector<int>(2 * n, 0));
        int ans = 0;
        for (auto [x1 , y1] : ones_1) {
            for (auto [x2 , y2] : ones_2) {
                ans = max(ans , ++shift[x1 - x2 + n][y1 - y2 + n]);
            }
        }
        return ans;
    }
};