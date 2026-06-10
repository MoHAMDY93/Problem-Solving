// Last updated: 6/10/2026, 7:19:19 PM
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i=0 ; i<n ; i++) if (nums[i] == target) ans = min(ans , abs(i - start));
        return ans;
    }
};