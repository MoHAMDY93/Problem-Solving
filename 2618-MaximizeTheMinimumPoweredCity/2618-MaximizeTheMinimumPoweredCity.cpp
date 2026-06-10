// Last updated: 6/10/2026, 7:16:08 PM
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> pref(n);
        pref[0] = stations[0];
        for(int i=1 ; i<n ; i++) pref[i] = stations[i] + pref[i-1];
        vector<long long> a;
        for(int i=0 ; i<n ; i++) {
            long long curr = (i + r < n ? pref[i+r] : pref.back()) - (i-r-1 >= 0 ? pref[i-r-1] : 0);
            a.push_back(curr);
        }
        auto check = [&](long long x) -> bool {
            vector<long long> add(n, 0);
            long long used = 0, window = 0;

            for (int i = 0; i < n; i++) {
                if (i - r - 1 >= 0) window -= add[i - r - 1]; 
                if (a[i] + window < x) {
                    long long need = x - (a[i] + window);
                    used += need;
                    if (used > k) return false;
                    window += need;
                    if (i + r < n) add[i + r] += need; 
                }
            }
            return true;
        };
        long long lo = *min_element(a.begin() , a.end()) , hi = *max_element(a.begin() , a.end()) + k;
        // cout << lo << ' ' << hi << '\n';
        long long ans = 0;
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(check(mid)) lo = mid+1 , ans = mid;
            else hi = mid-1;
            // cout << lo << ' ' << hi << '\n';
        }
        return ans;
    }
};