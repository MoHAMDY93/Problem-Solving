// Last updated: 6/10/2026, 7:23:12 PM
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int l = 1, r = 0;
        for (int p : piles) r = Math.max(r, p);

        int ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (count(piles, m) <= h) {
                ans = m;
                r = m - 1; 
            } else {
                l = m + 1; 
            }
        }
        return ans;
    }

    private long count(int[] a, int k) {
        long total = 0; 
        for (int bananas : a) {
            total += (bananas + k - 1) / k;
        }
        return total;
    }
}