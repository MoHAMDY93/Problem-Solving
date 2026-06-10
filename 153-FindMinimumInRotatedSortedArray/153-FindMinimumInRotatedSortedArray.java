// Last updated: 6/10/2026, 7:26:20 PM
class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int l = 0 , r = n-1 , ans = nums[0];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= ans) 
                l = mid+1;
            else {
                ans = nums[mid];
                r = mid-1;
            }
        }
        return ans;
    }
}