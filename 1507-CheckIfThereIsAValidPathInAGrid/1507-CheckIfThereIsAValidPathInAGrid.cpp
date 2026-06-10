// Last updated: 6/10/2026, 7:21:19 PM
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // directions: left, right, up, down
        vector<pair<int,int>> dirs = {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0}
        };

        // allowed directions for each type
        vector<vector<int>> mp = {
            {},
            {0, 1},       // 1: left, right
            {2, 3},       // 2: up, down
            {0, 3},       // 3: left, down
            {1, 3},       // 4: right, down
            {0, 2},       // 5: left, up
            {1, 2}        // 6: right, up
        };

        // opposite directions
        vector<int> opp = {1, 0, 3, 2};

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;

        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();

            if (x == n-1 && y == m-1) return true;

            for (int d : mp[grid[x][y]]) {
                int nx = x + dirs[d].first;
                int ny = y + dirs[d].second;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny])
                    continue;

                bool ok = false;
                for (int back : mp[grid[nx][ny]]) {
                    if (back == opp[d]) {
                        ok = true;
                        break;
                    }
                }

                if (ok) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};