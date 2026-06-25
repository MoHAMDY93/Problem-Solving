// Last updated: 6/25/2026, 3:06:45 PM
1class Solution {
2public:
3    int countMajoritySubarrays(vector<int>& nums, int target) {
4        int n = nums.size();
5        int ans = 0;
6        for (int i=0 ; i<n ; i++) {
7            int cnt = 0;
8            for (int j = i ; j<n ; j++) {
9                cnt += (nums[j] == target);
10                // cout << cnt << ' ' << j - i + 1 << '\n';
11                if (cnt > (j - i + 1) / 2) ans++; 
12            }
13            // cout << '\n';
14        }
15        return ans;
16    }
17};