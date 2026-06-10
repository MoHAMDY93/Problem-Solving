// Last updated: 6/10/2026, 7:20:03 PM
class Solution {
    private boolean check(int[][] tasks , int val) {
        for (var v : tasks) {
            if (val < v[1]) return false;
            val -= v[0];
        }
        return true;
    } 
    public int minimumEffort(int[][] tasks) {
        Arrays.sort(tasks , (a , b) -> ((b[1] - b[0]) - (a[1] - a[0])));
        int lo = 0 , hi = Integer.MAX_VALUE , ans = -1;
        while (lo <= hi) {
            int mid = (hi + lo) / 2;
            if (check(tasks , mid)) {
                ans = mid;
                hi = mid-1;
            } else 
                lo = mid + 1;
        }
        return ans;
    }
}