// Last updated: 6/10/2026, 7:26:23 PM
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<pair<int , int> , int> mp;
        int n = points.size();
        int ans = 0;
        for(int i=0 ; i<n ; i++) {
            int cnt = 0;
            for(int j = 0 ; j<n ; j++) {
                if(i == j) continue;
                int X = (points[i][0] - points[j][0]) , Y = (points[i][1] - points[j][1]);
                int gc = __gcd(abs(X) , abs(Y));
                // cout << X / gc << ' ' << Y / gc << '\n';
                mp[{X / gc , Y / gc}]++;
                cnt = max(cnt , mp[{X / gc , Y / gc}]);
            }
            ans = max(ans , cnt+1);
            mp.clear();
            // cout << '\n';
        } 
        // for(auto [_ , cnt] : mp) ans = max(ans , cnt);
        return ans;
    }
};