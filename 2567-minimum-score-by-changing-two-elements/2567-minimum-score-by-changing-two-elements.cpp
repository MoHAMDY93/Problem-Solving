class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if (nums.size() <= 3) return 0;
        int n = nums.size();
        sort(begin(nums) , end(nums));
        int ans = min({
            nums[n-1] - nums[2],
            nums[n-2] - nums[1],
            nums[n-3] - nums[0]
        });
        return ans;
    }
};