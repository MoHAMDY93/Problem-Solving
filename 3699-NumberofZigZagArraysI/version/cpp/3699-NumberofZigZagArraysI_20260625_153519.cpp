// Last updated: 6/25/2026, 3:35:19 PM
1const int N = 2005;
2const int MOD = 1e9 + 7;
3
4class Solution {
5public:
6    // memo[idx][val][state]
7    // Since R and L can be up to 2005, we offset the values to 0-indexed range [0, r - l]
8    int memo[N][N][2];
9    int nn, M;
10
11    int dp(int idx, int val_idx, int state) {
12        if (idx == nn - 1) return 1; // Reached the end successfully
13        
14        auto& ret = memo[idx][val_idx][state];
15        if (~ret) return ret;
16
17        ret = 0;
18        if (state == 0) {
19            // We need the next element to be LARGER than the current one
20            // We need values from val_idx + 1 up to M - 1
21            for (int next_val = val_idx + 1; next_val < M; next_val++) {
22                ret = (ret + dp(idx + 1, next_val, 1)) % MOD;
23            }
24        } else {
25            // We need the next element to be SMALLER than the current one
26            // We need values from 0 up to val_idx - 1
27            for (int next_val = 0; next_val < val_idx; next_val++) {
28                ret = (ret + dp(idx + 1, next_val, 0)) % MOD;
29            }
30        }
31        return ret;
32    }
33
34    int zigZagArrays(int n, int l, int r) {
35        nn = n;
36        M = r - l + 1;
37        
38        // Base case for single element array
39        if (n == 1) return M;
40
41        // Reset memo table up to actual size M to save memset overhead
42        for(int i = 0; i < n; i++) {
43            for(int j = 0; j < M; j++) {
44                memo[i][j][0] = -1;
45                memo[i][j][1] = -1;
46            }
47        }
48
49        // To completely bypass TLE in top-down, we fill the table backwards 
50        // to naturally compute the prefix sums for O(1) state resolution.
51        for (int idx = n - 2; idx >= 0; idx--) {
52            long long sum_state0 = 0;
53            long long sum_state1 = 0;
54            
55            // Pre-calculate cumulative answers for state 0 (smaller numbers)
56            vector<int> pref0(M, 0);
57            for (int v = 0; v < M; v++) {
58                sum_state0 = (sum_state0 + (idx == n - 2 ? 1 : memo[idx + 1][v][0])) % MOD;
59                pref0[v] = sum_state0;
60            }
61
62            // Pre-calculate cumulative answers for state 1 (larger numbers)
63            vector<int> suff1(M, 0);
64            for (int v = M - 1; v >= 0; v--) {
65                sum_state1 = (sum_state1 + (idx == n - 2 ? 1 : memo[idx + 1][v][1])) % MOD;
66                suff1[v] = sum_state1;
67            }
68
69            // Bind the precalculated range values straight back to your DP states
70            for (int v = 0; v < M; v++) {
71                memo[idx][v][0] = (v + 1 < M) ? suff1[v + 1] : 0;
72                memo[idx][v][1] = (v - 1 >= 0) ? pref0[v - 1] : 0;
73            }
74        }
75
76        long long ans = 0;
77        for (int v = 0; v < M; v++) {
78            ans = (ans + memo[0][v][0]) % MOD;
79            ans = (ans + memo[0][v][1]) % MOD;
80        }
81
82        return ans;
83    }
84};