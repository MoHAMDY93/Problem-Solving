// Last updated: 6/10/2026, 7:10:41 PM
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<vector<int>>> memo(n , vector<vector<int>>(m , vector<int>(k+1 , -1)));
        // int inv = INT_MIN / 2;
        function<int(int , int , int)> dp = [&](int i , int j , int cnt) -> int {
            if (cnt > k) return INT_MIN;
            if (i == n-1 && j == m-1) return ((cnt + (grid[i][j] > 0)) > k ? INT_MIN : grid[i][j]);
            auto& ret = memo[i][j][cnt];
            if (~ret) return ret;

            ret = INT_MIN;
            int val = grid[i][j] , cost = (grid[i][j] > 0);
            if (i+1 < n) ret = max(ret , val + dp(i+1 , j , cnt + cost));
            if (j+1 < m) ret = max(ret , val + dp(i , j+1 , cnt + cost));

            // cout << ret << '\n';

            return ret;
        };

        int ans = dp(0 , 0 , 0);
        return ans <= INT_MIN / 2 ? -1 : ans;
    }
};