// Last updated: 6/10/2026, 7:14:29 PM
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int , int> mp;
        int mx = 0;
        for(auto i : nums) mp[i]++ , mx = max(mx , mp[i]);
        int ans = 0;
        for(auto [_ , v] : mp) if(v == mx) ans += v;
        return ans;
    }
};