// Last updated: 6/10/2026, 7:16:28 PM
class Solution {
    public int[] applyOperations(int[] nums) {
        int n = nums.length;
        for(int i=0 ; i<n-1 ; i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        int idx = 0;
        for(int i : nums) {
            if(i != 0)
                nums[idx++] = i;
        }
        while(idx < n) {
            nums[idx++] = 0;
        }
        return nums;
    }
}