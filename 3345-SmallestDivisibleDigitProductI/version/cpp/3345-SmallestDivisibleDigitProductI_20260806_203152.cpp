// Last updated: 8/6/2026, 8:31:52 PM
1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        auto check = [&](int x) -> bool {
5            int rem = 1;
6            for ( ; x > 0 ; x /= 10) {
7                int d = x % 10;
8                // cout << d << ' ';
9                rem *= d;
10            }
11            rem %= t;
12            // cout << rem << '\n';
13            if (rem == 0) return true;
14            return false;
15        };  
16        for (; ; n++) {
17            if (check(n)) return n;
18        }
19        return -1;
20    }
21};