// Last updated: 8/5/2026, 1:22:30 AM
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        __int128_t vis = 0;
5        int mn = INT_MAX , mx = INT_MIN;
6        for (int i : nums) {
7            mn = min(mn , i);
8            mx = max(mx , i);
9            vis |= ((__int128_t)1 << i);
10        }
11        // cout << mn << ' ' << mx << '\n';
12        vector<int> ans;
13        for (int i=mn ; i <= mx ; i++) {
14            if ((vis >> i) & 1) continue;
15            // cout << i << '\n';
16            ans.push_back(i);
17        }
18        return ans;
19    }
20};