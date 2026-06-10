// Last updated: 6/10/2026, 7:10:30 PM
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;
        for(auto v : tasks) ans = min(ans , v[0] + v[1]);
        return ans;
    }
};