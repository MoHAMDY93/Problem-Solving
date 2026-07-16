// Last updated: 7/16/2026, 2:29:20 PM
1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> maxi(nums.begin() , nums.end());
6        for (int i=1 ; i<n ; i++) maxi[i] = max(maxi[i] , maxi[i-1]);
7        vector<int> gc(n);
8        for (int i=0 ; i<n ; i++) gc[i] = gcd(nums[i] , maxi[i]);
9        sort(gc.begin() , gc.end());
10        long long sum = 0;
11        for (int l=0 , r = n-1 ; l < r ; l++ , r--) sum += gcd(gc[l] , gc[r]);
12        return sum;
13    }
14};