// Last updated: 7/25/2026, 12:12:03 PM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int mx1 = -1 , mx2 = -1;
5        for (int tmp = n ; tmp ; tmp /= 10) {
6            int d = tmp % 10;
7            if (d > mx1) mx2 = mx1 , mx1 = d;
8            else if (d > mx2) mx2 = d;
9        }
10        return mx1 * mx2;
11    }
12};