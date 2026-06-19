// Last updated: 6/20/2026, 2:07:07 AM
1class Solution {
2    public int largestAltitude(int[] gain) {
3        int ans = 0;
4        int sum = 0;
5        for (int curr : gain) {
6            sum += curr;
7            ans = Math.max(ans , sum);
8        }   
9        return ans;
10    }
11}