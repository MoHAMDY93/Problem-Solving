// Last updated: 6/10/2026, 7:19:16 PM
class Solution {
    public int minPairSum(int[] nums) {
        int ans = 0;
        Arrays.sort(nums);
        int n = nums.length;
        for(int i=0 , j = n-1 ; i<j ; i++ , j--) {
            ans = Math.max(ans , nums[i] + nums[j]);
        }
        return ans;
    }
}