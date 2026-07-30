// Last updated: 7/31/2026, 2:56:08 AM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        int freq[26] = {0};
5        int cnt = 0;
6        for (auto c : word) {
7            if (freq[c - 'a'] == 0) cnt++;
8            freq[c - 'a']++; 
9        }
10        cout << cnt << '\n';
11        int total = 0;
12        total += min(8 , cnt);
13        if (cnt - 8 > 0)
14            total += min(8 , cnt - 8) * 2;
15        if (cnt - 16 > 0)
16            total += min(cnt - 16 , 8) * 3;
17        if (cnt - 24 > 0)
18            total += min(cnt - 24 , 2) * 4;
19        return total;
20    }
21};