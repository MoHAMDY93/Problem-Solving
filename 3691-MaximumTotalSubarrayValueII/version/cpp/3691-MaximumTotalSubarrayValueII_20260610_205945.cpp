// Last updated: 6/10/2026, 8:59:45 PM
/*
 * This is the toughest DS question solved on LC until now, the first sub problem is 373 LeetCode:
 * Find the smallest k pairs of two sorted arrays, the idea is simply we fix the first array pointer and add it with all the elements of the second array:
 * PQ = L[0] , R[i] -> where i is from 0 to m
 * Then at each time we pop an element of the PQ we increment the second pointer of that pair, this way we make sure that the whole time is O(n log n)
 * 
 * Backing to our problem, with small observation:
 * if we fixed one end of the subarray and moved the other one we will notice that the diff between max and min is montonic, either max got greater or min get smaller 
 * So we will follow the same way here, we fix the left pointer and add it with all possible Rs
 * PQ = (val {max - min} , l , n) where l = 0 -> n
 * then the PQ gets the max of them based on teh val in O(log n) then after each pop we check if the previous r was greater than curr l and if so we add new pair with new updated val
 * 
 * The max and min of range can be reached using RMQ with O(log n) complexity which fits perfect here
*/

1const int N = 1e5;
2class Solution {
3private:
4    int t_min[N][18], a[N];
5    void build_min(int n) {
6        for(int i = 1; i <= n; ++i) t_min[i][0] = a[i];
7        for(int k = 1; k < 18; ++k) {
8            for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
9                t_min[i][k] = min(t_min[i][k - 1], t_min[i + (1 << (k - 1))][k - 1]);
10            }
11        }
12    }
13
14    int query_min(int l, int r) {
15        int k = 31 - __builtin_clz(r - l + 1);
16        return min(t_min[l][k], t_min[r - (1 << k) + 1][k]);
17    }
18
19    int t_max[N][18];
20    void build_max(int n) {
21        for(int i = 1; i <= n; ++i) t_max[i][0] = a[i];
22        for(int k = 1; k < 18; ++k) {
23            for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
24                t_max[i][k] = max(t_max[i][k - 1], t_max[i + (1 << (k - 1))][k - 1]);
25            }
26        }
27    }
28
29    int query_max(int l, int r) {
30        int k = 31 - __builtin_clz(r - l + 1);
31        return max(t_max[l][k], t_max[r - (1 << k) + 1][k]);
32    }
33    
34public:
35    long long maxTotalValue(vector<int>& nums, int k) {
36        ios_base::sync_with_stdio(false);
37        cin.tie(NULL);
38        int n = nums.size();
39        for (int i=1 ; i<=n ; i++) a[i] = nums[i-1];
40        build_min(n) , build_max(n);
41        priority_queue<array<int, 3>> pq;
42        for (int l = 1; l <= n; l++) {
43            int val = query_max(l, n) - query_min(l, n);
44            pq.push({val , l , n});
45        }
46        long long ans = 0;
47        while (k--) {
48            auto [val , l , r] = pq.top();
49            pq.pop();
50            // cout << l << ' ' << r << ' ' << val << '\n';
51            // cout << l << ' ' << r << '\n';
52            // cout << query_max(l , r) << ' ' << query_min(l , r) << '\n';
53            ans += val;
54            if (r > l) {
55                int nval = query_max(l, r-1) - query_min(l, r-1);
56                pq.push({nval, l, r-1});
57            }
58        }
59        return ans;
60    }
61};