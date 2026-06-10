// Last updated: 6/10/2026, 7:21:38 PM
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ps(m+1, vector<int>(n+1, 0));

        // build prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                ps[i][j] = mat[i-1][j-1]
                        + ps[i-1][j]
                        + ps[i][j-1]
                        - ps[i-1][j-1];
            }
        }

        auto ok = [&](int len) {
            for (int i = 0; i + len <= m; i++) {
                for (int j = 0; j + len <= n; j++) {
                    int sum = ps[i+len][j+len]
                            - ps[i][j+len]
                            - ps[i+len][j]
                            + ps[i][j];
                    if (sum <= threshold)
                        return true;
                }
            }
            return false;
        };

        int lo = 0, hi = min(m, n), ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (ok(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};