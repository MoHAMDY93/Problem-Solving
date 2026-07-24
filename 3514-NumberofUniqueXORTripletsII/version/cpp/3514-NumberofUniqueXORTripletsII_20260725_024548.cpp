// Last updated: 7/25/2026, 2:45:48 AM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int m = 0;
5        for (int v : nums) {
6            m = max(m, v);
7        }
8        int u = 1;
9        while (u <= m) {
10            u <<= 1;
11        }
12        vector<int> s(u);
13        int n = nums.size();
14        for (int i = 0; i < n; i++) {
15            for (int j = i; j < n; j++) {
16                s[nums[i] ^ nums[j]] = 1;
17            }
18        }
19        vector<int> t(u);
20        for (int x = 0; x < u; x++) {
21            if (!s[x]) {
22                continue;
23            }
24            for (int v : nums) {
25                t[x ^ v] = 1;
26            }
27        }
28        int ans = 0;
29        for (int x = 0; x < u; x++) {
30            if (t[x]) {
31                ans++;
32            }
33        }
34        return ans;
35    }
36};