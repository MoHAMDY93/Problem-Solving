// Last updated: 6/10/2026, 7:26:14 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0 , r = n-1;
        while(l < r) {
            int sum = nums[l] + nums[r];
            if(sum < target)
                l++;
            else if(sum > target)
                r--;
            else {
                break;
            }
        }
        return {l+1 , r+1};
    }
};