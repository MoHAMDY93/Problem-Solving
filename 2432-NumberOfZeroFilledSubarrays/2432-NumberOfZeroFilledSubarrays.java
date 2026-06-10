// Last updated: 6/10/2026, 7:17:02 PM
class Solution {
    public long zeroFilledSubarray(int[] nums) {
        int n = nums.length;
        long ans = 0;
        for (int i=0 ; i<n ;) {
            if (nums[i] != 0) { i++; continue; }
            long cnt = 0;
            while (i < n && nums[i] == 0) { i++; cnt++; }
            ans += (cnt * (cnt + 1)) / (long)2;
        }
        return ans;
    }
}