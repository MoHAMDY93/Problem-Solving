// Last updated: 7/3/2026, 11:45:02 AM
1class Solution {
2public:
3    bool findSafeWalk(vector<vector<int>>& grid, int health) {
4        int n = grid.size() , m = grid[0].size();
5        int dx[] = {0 , 0 , -1 , 1};
6        int dy[] = {1 , -1 , 0 , 0};
7        vector<vector<int>> dist(n , vector<int> (m , 0));
8        queue<array<int , 3>> q;
9        q.push({health - grid[0][0] , 0 , 0});
10        dist[0][0] = health - (grid[0][0]);
11        while (!q.empty()) {
12            auto [h , x , y] = q.front(); q.pop();
13            if (x == n-1 && y == m-1 && h > 0) {
14                // cout << h << '\n';
15                return true;
16            }
17            if (h < dist[x][y]) continue;
18            for (int d=0 ; d<4 ; d++) {
19                int nx = x + dx[d] , ny = y + dy[d];
20                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
21                    int nh = h - grid[nx][ny];
22                    if (nh > dist[nx][ny]) {
23                        q.push({nh , nx , ny});
24                        dist[nx][ny] = nh;
25                    }
26                }
27            }
28        }
29        return false;
30    }
31};