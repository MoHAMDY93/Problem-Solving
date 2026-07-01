// Last updated: 7/1/2026, 2:23:33 PM
// قوي مووت
1class Solution {
2public:
3    int maximumSafenessFactor(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int dx[] = {1 , -1 , 0 , 0};
6        int dy[] = {0 , 0 , 1 , -1};
7        vector<vector<int>> dist(n ,vector<int> (n , INT_MAX));
8        queue<pair<int , int>> q;
9        for (int i=0 ; i<n ; i++) {
10            for (int j=0 ; j<n ; j++) {
11                if (grid[i][j]) q.push({i , j}) , dist[i][j] = 0;
12            }   
13        }
14        while (!q.empty()) {
15            auto [x , y] = q.front(); q.pop();
16            for (int i=0 ; i<4 ; i++) {
17                int nx = x + dx[i] , ny = y + dy[i];
18                if (0 <= nx && nx < n && 0 <= ny && ny < n && dist[nx][ny] > dist[x][y] + 1) {
19                    q.push({nx , ny});
20                    dist[nx][ny] = dist[x][y] + 1;
21                }
22            }
23        }
24        vector<vector<int>> best(n , vector<int>(n , -1));
25        priority_queue<pair<int , pair<int , int>>> pq;
26        best[0][0] = dist[0][0];
27        pq.push({dist[0][0] , {0 , 0}});
28        while (!pq.empty()) {
29            auto [d , p] = pq.top(); pq.pop();
30            auto [x , y] = p;
31            if (x == n-1 && y == n-1) return d;
32            if (d < best[x][y]) continue;
33            for (int i=0 ; i<4 ; i++) {
34                int nx = x + dx[i] , ny = y + dy[i];
35                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
36                    int nxt = min(dist[nx][ny] , d);
37                    if (nxt > best[nx][ny]) {
38                        best[nx][ny] = nxt;
39                        pq.push({nxt , {nx , ny}});
40                    }
41                }
42            }
43        }
44        return -1;
45    }
46};