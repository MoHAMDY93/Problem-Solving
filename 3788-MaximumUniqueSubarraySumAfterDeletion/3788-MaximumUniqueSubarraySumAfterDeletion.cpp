// Last updated: 6/10/2026, 7:12:08 PM
class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(begin(nums) , end(nums));
        nums.erase(unique(begin(nums) , end(nums)) , end(nums));
        if(nums.size() == 1)
            return nums[0];
        int i = nums.size()-1;
        int ans = nums[i--];
        while(i >= 0 && nums[i] > 0) ans += nums[i--];
        return ans; 
    }
};