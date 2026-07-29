// Last updated: 7/29/2026, 11:45:37 PM
1constexpr int INF=1e6+1, N=24;
2int C[N][N]={{0}};
3
4constexpr void Pascal() {
5    if (C[0][0]==1) return; // computed once
6    C[0][0]=1;
7    for (int i=1; i<N; i++) {
8        C[i][0]=C[i][i]=1;
9        for (int j=1; j<=i/2; j++) {
10            C[i][j]=C[i][i-j]=C[i-1][j-1]+C[i-1][j];
11        }
12    }
13}
14
15class Solution {
16public:
17    static int comb(int n, int k) {
18        if (n<N) return C[n][k];//  look at the table
19        if (2*k>n) k=n-k;// C(n, n-k)=C(n, k)
20        int64_t ans=1;
21        for (int i=1; i<=k; i++) {
22            ans=ans*(n-i+1)/i;
23            if (ans>=INF) return INF;
24        }
25        return ans;
26    }
27
28    static inline int perm(const array<int, 26>& freq, unsigned seen, int sz) {
29        int64_t ans=1;
30        for ( ; seen; seen&=(seen-1)) {
31            const int c=__builtin_ctz(seen);
32            const int f=freq[c];
33            ans*=comb(sz, f);
34            if (ans>=INF) return INF;
35            sz-=f;
36        }
37        return ans;
38    }
39
40    static string smallestPalindrome(string& s, int k) {
41        Pascal();
42        const int n=s.size(), n0=n/2;
43        array<int, 26> freq={0};
44        unsigned seen=0;
45        for (int i=0; i<n0; i++){
46            const int idx=s[i]-'a';
47            freq[idx]++;
48            seen|=1<<idx;
49        }
50        int total=perm(freq, seen, n0);
51        if (k>total) return "";
52
53        string left;
54        left.reserve(n);
55        int sz=n0;
56        for (int i=0; i<n0; i++) {
57            for (int c=0; c<26; c++) {
58                if (freq[c]==0) continue;
59                freq[c]--;
60                int cnt=perm(freq, seen, --sz);
61                if (cnt>=k) {
62                    left.push_back('a' + c);
63                    seen&=(~((freq[c]==0)<<c));
64                    break;
65                } 
66                else {
67                    k-=cnt;
68                    freq[c]++;// backtrack
69                    sz++;
70                }
71            }
72        }
73
74        string right=left;
75        reverse(right.begin(), right.end());
76        if (n&1) left.push_back(s[n0]);
77        left.append(right);
78        return left;
79    }
80};
81
82auto init = []() {
83    ios::sync_with_stdio(false);
84    cin.tie(nullptr);
85    cout.tie(nullptr);
86    return 'c';
87}();