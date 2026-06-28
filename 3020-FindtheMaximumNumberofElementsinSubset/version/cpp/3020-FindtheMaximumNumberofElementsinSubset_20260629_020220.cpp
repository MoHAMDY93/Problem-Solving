// Last updated: 6/29/2026, 2:02:20 AM
1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        unordered_map<int , int> freq;
5        for (auto& i : nums) freq[i]++;
6        int ans = max(0 , freq[1] - ((freq[1] + 1) & 1));
7        for (auto [val , _] : freq) {
8            if (val == 1) continue;
9            int cnt = 0;
10            long long prev = val;
11            for (long long mul = val ; freq.count(mul) && mul < 1e9 ; mul *= prev) {
12                if (freq[mul] > 1) {
13                    ans = max(ans , cnt+1);
14                    cnt += 2;
15                    prev = mul;
16                }
17                else {
18                    ans = max(ans , cnt + 1); 
19                    break;
20                }
21            }
22        }
23        return ans;
24    }
25};