// Last updated: 6/10/2026, 7:27:49 PM
class Solution {
    public int search(int[] nums, int target) {
        int l = 0 , r = nums.length - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        int pos = l;
        int left = 0 , right = pos - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid-1;
            else if(nums[mid] < target) left = mid+1;
            else return mid;
        }
        left = pos; right = nums.length-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid-1;
            else if(nums[mid] < target) left = mid+1;
            else return mid;
        }
        return -1;
    }
}