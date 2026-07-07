// Last updated: 7/7/2026, 11:43:01 PM
1class Solution {
2public:
3    long long sumAndMultiply(int n) {
4        long long ret = 0;
5        long long cnt = 0;
6        long long sum = 0;
7        for ( ; n ; n /= 10) {
8            int d = n % 10;
9            if (d == 0) continue;
10            sum += d;
11            ret = pow(10 , cnt) * (d) + ret;
12            cnt++;
13        }
14        return ret * sum;
15    }
16};