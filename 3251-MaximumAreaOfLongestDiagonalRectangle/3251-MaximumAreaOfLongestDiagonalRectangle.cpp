// Last updated: 6/10/2026, 7:14:27 PM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long mx = 0;
        int res = -1;
        for(auto v : dimensions) {
            int x = v[0] , y = v[1];
            long long d = x*x + y*y;
            if(d > mx) mx = d , res = x * y;
            else if(d == mx) res = max(res , x * y);
        }
        return res;
    }
};