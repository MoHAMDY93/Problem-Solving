// Last updated: 6/28/2026, 1:01:49 PM
/*
 * EAZYYYYYYYY, and i am a dumbbbbbbbbb man
 * If u thought about recursive it is a hell of states and transitions, but with the iterative approach it is so fucken easy
*/

1class Solution {
2public:
3    long long maxSubarraySum(vector<int>& A, int k) {
4        long long res = -1e9, dp0 = 0, dpb = 0, dpc = 0, dp1 = 0;
5        for (long long a: A) {
6            long long b = a * k, c = a / k;
7            dp1 = max({dp1 + a, dpb + a, dpc + a});
8            dpb = max({dp0 + b, dpb + b, b});
9            dpc = max({dp0 + c, dpc + c, c});
10            dp0 = max(dp0 + a, a);
11            res = max({res, dp0, dpb, dpc, dp1});
12        }
13        return res;
14    }
15};
16auto init = [] {
17    ios::sync_with_stdio(false);
18    cin.tie(nullptr);
19    return 0;
20}();