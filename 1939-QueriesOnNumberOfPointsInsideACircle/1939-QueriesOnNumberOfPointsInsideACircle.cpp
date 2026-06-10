// Last updated: 6/10/2026, 7:19:24 PM
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto v : queries) {
            int x = v[0] , y = v[1] , r = v[2];
            int cnt = 0;
            for(auto u : points) {
                int X = u[0] , Y = u[1];
                int C = ((x - X) * (x - X) + (y - Y) * (y - Y));
                cnt += (C <= r * r);
            }
            res.push_back(cnt);
        }
        return res;
    }
};