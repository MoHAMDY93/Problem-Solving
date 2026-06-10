// Last updated: 6/10/2026, 7:23:42 PM
class Solution {
public:
    struct T {
        int t , x , y;
        T(int a , int b , int c) : t(a) , x(b) , y(c) {}
        bool operator< (const T &d) const {return t > d.t;}
    };
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[] = {1 , -1 , 0 , 0};
        int dy[] = {0 , 0 , 1 , -1};
        priority_queue<T> pq;
        pq.push(T(grid[0][0] , 0 , 0));
        vector<vector<bool>> seen(n , vector<bool> (n , false));
        seen[0][0] = true;
        int res = 0;
        while(true) {
            auto p = pq.top(); pq.pop();
            res = max(res , p.t);
            if(p.x == n-1 && p.y == n-1) return res;
            for(int i=0 ; i<4 ; i++) {
                int nx = p.x + dx[i] , ny = p.y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !seen[nx][ny]) {
                    seen[nx][ny] = true;
                    pq.push(T(grid[nx][ny] , nx , ny));
                }
            }
        }
        return -1;
    }
};