// Last updated: 6/10/2026, 7:25:39 PM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l=0 , r = 0 , sum = 0 , ans = INT_MAX;
        while(r < n) {
            sum += nums[r++];
            while(sum >= target) {
                ans = min(ans , r - l);
                sum -= nums[l++];
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};