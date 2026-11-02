class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int ans = 0 , n = nums.size();
        for (int i : nums) ans += abs(i - nums[n / 2]);
        return ans;
    }
};