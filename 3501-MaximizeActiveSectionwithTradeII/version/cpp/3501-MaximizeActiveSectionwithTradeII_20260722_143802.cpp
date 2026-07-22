// Last updated: 7/22/2026, 2:38:02 PM
1class SparseTable {
2private:
3    vector<vector<int>> st;
4
5public:
6    SparseTable(const vector<int>& data) {
7        st.push_back(data);
8        int i = 1, N = st[0].size();
9        while (2 * i <= N + 1) {
10            const auto& pre = st.back();
11            vector<int> cur;
12            for (int j = 0; j < N - 2 * i + 1; j++) {
13                cur.push_back(max(pre[j], pre[j + i]));
14            }
15            st.push_back(cur);
16            i <<= 1;
17        }
18    }
19
20    int query(int begin, int end) {
21        if (begin > end) {
22            return 0;
23        }
24        int len = end - begin + 1;
25        int lg = 0;
26        while ((1 << (lg + 1)) <= len) {
27            lg++;
28        }
29        return max(st[lg][begin], st[lg][end - (1 << lg) + 1]);
30    }
31};
32
33class Solution {
34public:
35    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
36        int n = s.length();
37        int init = count(s.begin() , s.end() , '1');
38        vector<int> zeroBlocks , leftBlock , rightBlock;
39        int i=0;
40        while (i < n) {
41            int st = i;
42            while (i < n && s[i] == s[st]) i++;
43            if (s[st] == '0') {
44                zeroBlocks.push_back(i - st);
45                leftBlock.push_back(st);
46                rightBlock.push_back(i - 1);
47            }
48        }
49        int m = zeroBlocks.size();
50        if (m < 2) return vector<int> (queries.size() , init);
51        vector<int> sum(m-1);
52        for (int i=0 ; i+1<m ; i++) sum[i] = zeroBlocks[i] + zeroBlocks[i+1];
53        SparseTable st(sum);
54        vector<int> ans;
55        for (const auto& q : queries) {
56            int l = q[0] , r = q[1];
57            int i = lower_bound(rightBlock.begin() , rightBlock.end() , l) - rightBlock.begin();
58            int j = upper_bound(leftBlock.begin() , leftBlock.end() , r) - leftBlock.begin() - 1;
59            if (i > m-1 || j < 0 || i >= j) {
60                ans.push_back(init);
61                continue;
62            }
63            int fLen = rightBlock[i] - max(leftBlock[i] , l) + 1;
64            int eLen = min(rightBlock[j] , r) - leftBlock[j] + 1;
65            if (i + 1 == j) {
66                ans.push_back(init + fLen + eLen);
67                continue;
68            }
69            int val1 = fLen + zeroBlocks[i+1];
70            int val2 = eLen + zeroBlocks[j-1];
71            int val3 = st.query(i+1 , j-2);
72            int bestGain = max({val1 , val2 , val3});
73            ans.push_back(init + bestGain);
74        }
75        return ans;
76    }   
77};