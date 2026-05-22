class Solution {
    public boolean isGood(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length-1;
        for (int i=1 ; i<=n ; i++) {
            if (nums[i-1] != i) return false;
        }
        return nums[n] == n ? true : false;
    }
}