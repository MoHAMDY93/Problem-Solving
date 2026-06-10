// Last updated: 6/10/2026, 7:11:09 PM
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int ans = INT_MAX;
        sort(nums.begin() , nums.end());
        for(int i=0 ; i<nums.size() ; i++) {
            auto it = upper_bound(nums.begin() , nums.end() , 1LL * k * nums[i]);
            it = prev(it);
            // if(it == nums.end() || *it > 1LL * k * nums[i]) it = prev(it);
            int right = nums.size() - (it - nums.begin()) - 1;
            ans = min(ans , i + right);
        }
        return ans;
    }
};