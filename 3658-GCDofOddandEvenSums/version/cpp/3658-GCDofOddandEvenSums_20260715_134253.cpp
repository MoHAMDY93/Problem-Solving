// Last updated: 7/15/2026, 1:42:53 PM
1class Solution {
2public:
3    int gcdOfOddEvenSums(int n) {
4        return gcd(n*n , n * (n+1));
5    }
6};