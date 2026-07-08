// Last updated: 7/8/2026, 12:39:43 PM
// لييييه
1class Solution {
2public:
3    const int MOD = 1e9 + 7;
4    const int N = 1e5 + 5;
5    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
6        int n = s.size();
7        __int128_t prev = 0;
8        vector<__int128_t> sum(n) , num(n , 0);
9        vector<int> cnt(n , 0);
10        for (int i=0 ; i<n ; i++) {
11            char c = s[i];
12            sum[i] = c - '0';
13            cnt[i] = (int)(c != '0');
14            if (i) sum[i] += sum[i-1] , cnt[i] += cnt[i-1];
15            if (c != '0') {
16                num[i] = ((10 * prev % MOD) + (c - '0')) % MOD;
17                prev = num[i];
18            } else 
19                num[i] = prev;
20        }
21        // for (auto i : sum) cout << i << ' ';
22        // cout << '\n';
23        // for (auto i : cnt) cout << i << ' ';
24        // cout << '\n';
25        // for (auto i : num) cout << i << ' ';
26        // cout << '\n';
27        __int128_t p10[N];
28        p10[0] = 1;
29        for (int i = 1; i < N; i++)
30            p10[i] = p10[i - 1] * 10 % MOD;
31        vector<int> ans;
32        for (auto q : queries) {
33            int l = q[0] , r = q[1];
34            __int128_t csum = sum[r] - (l > 0 ? sum[l-1] : 0);
35            __int128_t rnum = num[r];
36            __int128_t lnum = (l > 0 ? num[l-1] : 0);
37            if (lnum) lnum = lnum * p10[cnt[r] - cnt[l - 1]] % MOD;
38            __int128_t diff = (((rnum%MOD) - (lnum%MOD)) + MOD) % MOD;
39            // cout << csum << ' ' << lnum << ' ' << rnum << '\n';
40            ans.push_back((csum * diff % MOD + MOD) % MOD);
41        }
42        return ans;
43    }
44};