// Last updated: 6/10/2026, 7:11:00 PM
class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> jurnavalic;
        jurnavalic.reserve(n);
        
        for (int x : nums) jurnavalic.push_back(abs(x));
        
        sort(jurnavalic.begin(), jurnavalic.end());
        
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            int a = jurnavalic[i];
            int L = (a + 1) / 2;   
            int R = 2 * a;
            
            auto low = lower_bound(jurnavalic.begin() + i + 1, jurnavalic.end(), L);
            auto high = upper_bound(jurnavalic.begin() + i + 1, jurnavalic.end(), R);
            
            ans += (high - low);
        }
        
        return ans;
    }
};
