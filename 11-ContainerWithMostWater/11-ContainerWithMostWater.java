// Last updated: 6/10/2026, 7:28:23 PM
class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int l = 0 , r = n-1;
        int res = 0;
        while (l < r) {
            res = Math.max(res , Math.min(height[l] , height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return res;
    }
}