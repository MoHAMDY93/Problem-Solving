// Last updated: 6/10/2026, 7:22:33 PM
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> a;
        long long ans = 0;
        for(auto v : costs) {
            ans += v[0];
            a.push_back(v[1] - v[0]);
        }
        sort(a.begin() , a.end());
        int n = costs.size() / 2;
        for(int i=0 ; i<n ; i++) ans += a[i];
        return ans;
    }
};