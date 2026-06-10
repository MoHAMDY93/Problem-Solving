// Last updated: 6/10/2026, 7:15:23 PM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        unordered_set<int>st;
        for(int i : nums)
            st.insert(i);
        
        int l = 0 , r = 0 , cnt = 0;
        unordered_map<int , int>mp;
        while (r < n) {
            mp[nums[r]]++;
            while (mp.size() == st.size()) {
                ans += (n - r);
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};