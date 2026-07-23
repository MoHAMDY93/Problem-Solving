// Last updated: 7/24/2026, 12:50:54 AM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int n = nums.size();
5        if (n <= 2) return n;
6        int lg = ceil(log2(n + 1));
7        return (1 << lg);
8    }
9};