// Last updated: 6/10/2026, 7:12:09 PM
class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        auto convert = [&](vector<int> point) -> long long {
            long long x = point[0] , y = point[1];
            if (y == 0) return x;
            else if (x == side) return side + y;
            else if (y == side) return 2LL * side + (side - x);
            else return 3LL * side + (side - y); 
        };
        vector<long long> a;
        for (auto& v : points) a.push_back(convert(v));
        sort(a.begin() , a.end());
        // for (auto p : a) cout << p << '\n';
        auto check = [&](int d) -> bool {
            for (int i=0 ; i<n ; i++) {
                long long cur = a[i];
                long long end = a[i] + 4LL * side - d;
                bool ok = true;
                for (int j=0 ; j<k-1 ; j++) {
                    auto next = lower_bound(a.begin() , a.end() , cur + d);
                    if (next == a.end() || *next > end) {ok = false; break;}
                    cur = *next;
                } 
                if (ok) return true;
            }
            return false;
        };
        int lo = 1 , hi = side;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo - 1;
    }
};