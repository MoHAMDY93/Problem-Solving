// Last updated: 6/10/2026, 7:11:29 PM
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int MOD = 1000000007;
        sort(points.begin() , points.end() , [](const auto &a , const auto &b) {
            if(a[1] == b[1]) 
                return a[0] < b[0];
            return a[1] < b[1];
        });
        long long cnt = 0 , prev = points[0][1] , res = 0, total = 0;
        for(auto p : points) {
            // cout << cnt << '\n';
            if(p[1] == prev) cnt++;
            else {
                long long lines = (1LL * cnt * (cnt-1)) / 2;
                res = (res + total * lines) % MOD;
                total = (total + lines) % MOD;
                prev = p[1] , cnt = 1;
            }
        }
        long long lines = (1LL * cnt * (cnt-1)) / 2;
        res = (res + total * lines) % MOD;
        total = (total + lines) % MOD;
        return res;
    }
};