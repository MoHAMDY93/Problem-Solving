// Last updated: 6/25/2026, 3:31:55 PM
// قوية اوي
1const int N = 1e5 + 5;
2class Solution {
3public:
4    long long bit[N];
5
6    void update_point(int idx , long long val) {
7        for (int i = idx ; i < N ; i += (i & -i)) {
8            bit[i] += val;
9        }
10    }
11
12    long long query(int idx) {
13        long long sum = 0;
14        for (int i= idx ; i>=1 ; i -= (i & -i))
15            sum += bit[i];
16        return sum;
17    }
18
19    long long countMajoritySubarrays(vector<int>& nums, int target) {
20        int n = nums.size();
21        vector<int> count(n , 0);
22        for (int i=0 ; i<n ; i++) count[i] = (nums[i] == target ? +1 : -1);
23        int mn = min(-1 , count[0]);
24        for (int i=1 ; i<n ; i++) {
25            count[i] += count[i-1];
26            mn = min(mn , count[i]);
27        }
28        for (int i=0 ; i<n ; i++) count[i] += (-1 * mn + 1);
29        update_point(-1*mn + 1 , +1);
30        long long ans = 0;
31        for (int cnt : count) {
32            cout << cnt << ' ';
33            ans += query(cnt-1);
34            update_point(cnt , +1);
35        }
36        return ans;
37    }
38};