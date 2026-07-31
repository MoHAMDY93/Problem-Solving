// Last updated: 7/31/2026, 3:01:13 AM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        int freq[26] = {0};
5        int cnt = 0;
6        for (auto c : word) {
7            if (freq[c - 'a'] == 0) cnt++;
8            freq[c - 'a']++; 
9        }
10        vector<int> ord(26);
11        iota(begin(ord) , end(ord) , 0);
12        sort(begin(ord) , end(ord) , [&](int& a , int& b) {
13            return freq[a] > freq[b];
14        });
15        int ans = 0;
16        for (int c=0 ; c<26 ; c++) {
17            ans += ((c / 8) + 1) * freq[ord[c]];
18        }
19        return ans;
20    }
21};