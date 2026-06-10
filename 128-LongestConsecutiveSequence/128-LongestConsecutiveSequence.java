// Last updated: 6/10/2026, 7:26:36 PM
class Solution {
    public int longestConsecutive(int[] nums) {
        Arrays.sort(nums);
        int cnt = 1 , n = nums.length , ans = 1;
        if (n == 0) return 0; 
        for (int i=1 ; i<n ; i++) {
            if (nums[i] == nums[i-1] + 1) cnt++;
            else if (nums[i] > nums[i-1] + 1) {
                cnt = 1;
            }
            ans = Math.max(cnt , ans);
        }
        return ans;
    }
}