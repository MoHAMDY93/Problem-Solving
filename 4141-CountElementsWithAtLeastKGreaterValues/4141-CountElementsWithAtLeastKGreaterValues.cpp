// Last updated: 6/10/2026, 7:08:59 PM
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        map<int , int> mp;
        for(auto i : nums) mp[i]++;
        sort(nums.begin() , nums.end());
        nums.erase(unique(nums.begin() , nums.end()) , nums.end());
        int ans = 0 , cnt = 0;
        for(int i=nums.size()-1 ; i>=0 ; i--) {
            if(cnt >= k) ans += mp[nums[i]];
            cnt += mp[nums[i]];
        }
        return ans;
    }
};