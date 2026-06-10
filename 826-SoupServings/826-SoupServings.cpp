// Last updated: 6/10/2026, 7:23:28 PM
class Solution {
public:
    double soupServings(int n) {
        // Shortcut for very large n
        if (n >= 4800) return 1.0;

        int N = (n + 24) / 25;               // scale down by 25 (ceil)
        vector<vector<double>> memo(N + 1, vector<double>(N + 1, -1.0));

        function<double(int,int)> dfs = [&](int a, int b) -> double {
            if (a <= 0 && b <= 0) return 0.5;
            if (a <= 0) return 1.0;
            if (b <= 0) return 0.0;

            if (memo[a][b] >= 0) return memo[a][b];

            // scaled steps: 100->4, 75->3, 50->2, 25->1
            memo[a][b] = 0.25 * (
                dfs(max(0, a - 4), b)
                + dfs(max(0, a - 3), max(0, b - 1))
                + dfs(max(0, a - 2), max(0, b - 2))
                + dfs(max(0, a - 1), max(0, b - 3))
            );
            return memo[a][b];
        };

        return dfs(N, N);
    }
};