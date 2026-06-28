// Last updated: 6/29/2026, 1:56:43 AM
// That is fucking cool, i used the loop of multiples
1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        map<int , int> freq;
5        for (auto& i : nums) freq[i]++;
6        int ans = max(0 , freq[1] - ((freq[1] + 1) & 1));
7        for (auto [val , _] : freq) {
8            if (val == 1) continue;
9            int cnt = 0;
10            long long prev = val;
11            for (long long mul = val ; freq.count(mul) && mul < 1e9 ; mul *= prev) {
12                // cout << mul << '\n';
13                if (freq[mul] > 1) {
14                    ans = max(ans , cnt+1);
15                    cnt += 2;
16                    prev = mul;
17                }
18                else {
19                    ans = max(ans , cnt + 1); 
20                    break;
21                }
22            }
23        }
24        return ans;
25    }
26};