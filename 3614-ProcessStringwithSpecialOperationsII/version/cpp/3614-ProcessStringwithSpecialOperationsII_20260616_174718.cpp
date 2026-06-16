// Last updated: 6/16/2026, 5:47:18 PM
// Simulate the k backwards until we reach the exact position, pace of cake but only after seeing the hits
1class Solution {
2public:
3    /*
4            " a # b % *"
5    len:    0 1 2 3 3 2
6    backward pass:
7        k = 1 at * -> continue
8        k = 1 at % -> k = 3 - 1 - 1 = 1
9        k = 1 at b -> does k == prev ? nope
10        k = 1 at # -> does k >= prev?  yupp so it lies in teh second half, k -= prev = 0
11        k = 0 at a -> does k = prev ? yupp, so the char is a
12    */
13    char processStr(string s, long long k) {
14        int n = s.size();
15        vector<long long> len(n);
16        long long L = 0;
17        for (int i=0 ; i<n ; i++) {
18            char c = s[i];
19            if ('a' <= c && c <= 'z') L++;
20            else if (c == '*') L = (L > 0 ? L-1 : 0);
21            else if (c == '#') L <<= 1;
22            len[i] = L;
23        }   
24        // for (auto l : len) cout << l << ' ';
25        // cout << '\n';
26        if (k >= len[n-1]) return '.';
27        for (int i=n-1 ; i >= 0 ; i--) {
28            char c = s[i];
29            long long curr = len[i];
30            long long prev = (i > 0 ? len[i-1] : 0);
31            if ('a' <= c && c <= 'z') {
32                if (k == prev) return c;
33            } else if (c == '*') {
34                continue;
35            } else if (c == '#') {
36                if (k >= prev) k -= prev;
37            } else {
38                k = curr - 1 - k;
39            }
40        }
41        return '.';
42    }
43};