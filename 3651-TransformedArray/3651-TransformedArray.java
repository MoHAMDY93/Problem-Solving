// Last updated: 6/10/2026, 7:12:49 PM
class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        for(int i=0 ; i<n ; i++) {
            res[i] = nums[(((i + nums[i]) % n) + n) % n];
        }
        return res;
    }
}