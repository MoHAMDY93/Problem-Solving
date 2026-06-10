// Last updated: 6/10/2026, 7:23:44 PM
class Solution {
    public int search(int[] nums, int target) {
        Arrays.sort(nums);
        int idx = Arrays.binarySearch(nums , target); 
        return (idx < 0 ? -1 : idx);
    }
}