// Last updated: 7/17/2026, 3:55:59 AM
1class Solution {
2public:
3    const int N = 5e4 + 5;
4    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
5        vector<int> freq(N , 0);
6        for (int i : nums) freq[i]++;
7        vector<long long> total(N , 0);
8        for (int gc = 1 ; gc<N ; gc++) {
9            for (int mul = gc ; mul < N ; mul += gc)
10                total[gc] += freq[mul];
11        }   
12        vector<long long> cnt(N , 0);
13        for (int gc = N-1 ; gc>0 ; gc--) {
14            cnt[gc] = 1LL * total[gc] * (total[gc] - 1) / 2;
15            for (int mul = 2*gc ; mul < N ; mul += gc)
16                cnt[gc] -= cnt[mul];
17        }
18        int n = queries.size();
19        vector<int> ord(n);
20        iota(ord.begin() , ord.end() , 0);
21        sort(ord.begin() , ord.end() , [&](int A , int B) {
22            return queries[A] < queries[B];
23        });
24        vector<int> ans(n);
25        long long curr_cnt = 0 , curr_gc = 1;
26        for (int i=0 ; i<n ; i++) {
27            long long q = queries[ord[i]];
28            while (curr_cnt + cnt[curr_gc] <= q) {
29                curr_cnt += cnt[curr_gc];
30                curr_gc++;
31            }
32            ans[ord[i]] = curr_gc;
33        }
34        return ans;
35    }
36};