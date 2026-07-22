// Last updated: 7/22/2026, 1:47:59 PM
1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        s = "1" + s + "1";
5        int total = 0;
6        int cnt = 0 , prev = 1 , fst = 0;
7        vector<pair<int ,int>> blocks;
8        for (auto c : s) {
9            if (c - '0' == prev) cnt++;
10            else {
11                if (prev == 1) total += cnt - (fst == 0);
12                blocks.emplace_back(prev , cnt);
13                prev = c - '0';
14                cnt = 1 , fst = 1;
15            }
16        }
17        if (s.back() == '1') total += cnt - 1;
18        blocks.emplace_back(s.back() - '0' , cnt);
19        int n = blocks.size();
20        if (n == 1) return blocks[0].second - 2;
21        vector<int> pref(n);
22        for (int i=0 ; i<n ; i++) {
23            pref[i] = blocks[i].second;
24            if (i) pref[i] += pref[i-1];
25        }
26        int ans = total;
27        for (int i=1 ; i+1<n ; i++) {
28            if (blocks[i].first == 1) {
29                int curr = blocks[i].second;
30                int inc = pref[i+1] - pref[i-2];
31                ans = max(ans , total - curr + inc);
32            }
33        }
34        return ans;
35    }
36};