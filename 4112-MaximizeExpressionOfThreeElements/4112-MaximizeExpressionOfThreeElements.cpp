// Last updated: 6/10/2026, 7:09:43 PM
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        return nums[n-1] + nums[n-2] - nums[0];
    }
};