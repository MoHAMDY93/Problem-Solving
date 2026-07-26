// Last updated: 7/26/2026, 6:43:23 PM
1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        int n = nums.size();
5        sort(rbegin(nums) , rend(nums));
6        return max(nums[0] * nums[1] * nums[2] , nums[0] * nums[n-1] * nums[n-2]);
7
8    }
9};