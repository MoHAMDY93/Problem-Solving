// Last updated: 7/15/2026, 7:49:57 PM
1class Solution {
2public:
3    bool checkValidGrid(vector<vector<int>>& grid) {
4        int dx[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
5        int dy[] = {-1 , 1 , -2 , 2 , -2 , 2 , -1 , 1};
6        int n = grid.size();
7        auto check = [&](int x , int y) -> bool {
8            return 0 <= x && x < n && 0 <= y && y < n;
9        };
10        vector<pair<int , int>> pos(n*n);
11        for (int i=0 ; i<n ; i++) {
12            for (int j=0 ; j<n ; j++) {
13                pos[grid[i][j]] = {i , j};
14            }
15        }   
16        auto [prevX , prevY] = pos[0];
17        if (prevX || prevY) return false; 
18        for (int i=1 ; i<n*n; i++) {
19            auto [x , y] = pos[i];
20            // cout << x << ' ' << y << '\n';
21            bool ok = false;
22            for (int d=0 ; d<8 ; d++) {
23                int nx = prevX + dx[d] , ny = prevY + dy[d];
24                if (check(nx , ny) && nx == x && ny == y) { ok = true; break; } 
25            }
26            if (!ok) return false;
27            prevX = x , prevY = y;
28        }    
29        return true;
30    }
31};