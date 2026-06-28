// Last updated: 6/28/2026, 5:33:28 AM
1class Solution {
2public:
3    long long maxSum(vector<int>& nums, int k, int mul) {
4        sort(nums.rbegin() , nums.rend());
5        long long ans = 0;
6        for (int i=0 ; i<k ; i++) {
7            if (mul) { ans += 1LL * nums[i] * mul; mul--; }
8            else ans += nums[i];
9        }
10        return ans;
11    }
12};