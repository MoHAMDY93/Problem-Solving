// Last updated: 6/10/2026, 7:11:03 PM
class Solution {
    public int minRemoval(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        // int ans = Integer.MAX_VALUE;
        int left = 0, mx = 0;
        for(int r=0 ; r<n ; r++) {
            while(nums[r] > 1L * nums[left] * k) left++;
            mx = Math.max(mx , r - left + 1);
        }
        return n - mx;
    }
}