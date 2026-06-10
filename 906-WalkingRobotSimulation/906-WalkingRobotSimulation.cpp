// Last updated: 6/10/2026, 7:23:14 PM
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        /* 
            0 -> north
            1 -> east
            2 -> south
            3 -> west
        */
        int dir = 0;
        map<int , set<int>> rows , cols;
        for (auto& v : obstacles) {
            rows[v[0]].insert(v[1]);
            cols[v[1]].insert(v[0]);
        }
        int ans = 0;
        int x=0 , y=0;
        for (auto op : commands) {
            if (op == -1) dir = (dir + 1) % 4;
            else if (op == -2) dir = (((dir - 1) % 4) + 4) % 4;
            else {
                if (dir == 0) {
                    auto it = rows[x].upper_bound(y);
                    int cand = INT_MAX;
                    if (it != rows[x].end()) cand = *it - 1; 
                    y = min(y + op , cand);
                } else if (dir == 2) {
                    auto it = rows[x].upper_bound(y);
                    int cand = INT_MIN;
                    if (it != rows[x].begin()) cand = *prev(it) + 1; 
                    y = max(y - op , cand);
                } else if (dir == 1) {
                    auto it = cols[y].upper_bound(x);
                    int cand = INT_MAX;
                    if (it != cols[y].end()) cand = *it - 1; 
                    x = min(x + op , cand);
                } else if (dir == 3) {
                    auto it = cols[y].lower_bound(x);
                    int cand = INT_MIN;
                    if (it != cols[y].begin()) cand = *prev(it) + 1; 
                    x = max(x - op , cand);
                }
                cout << x << ' ' << y << '\n';
                ans = max(ans , x*x + y*y);
            }
        }
        return ans;
    }
};