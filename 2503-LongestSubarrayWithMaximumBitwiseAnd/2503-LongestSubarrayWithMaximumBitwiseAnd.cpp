// Last updated: 6/10/2026, 7:16:44 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(begin(nums) , end(nums));
        int cnt = 0 , ans = 0;
        for(auto num : nums) {
            if(num == mx) cnt++;
            else cnt = 0;
            ans = max(ans , cnt);
        }
        return ans;
    }
};