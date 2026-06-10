// Last updated: 6/10/2026, 7:16:04 PM
class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int n = nums1.length , m = nums2.length;
        for (int i=0 , j=0 ; i<n && j < m ; ) {
            if (nums1[i] == nums2[j]) return nums1[i];
            else if (nums1[i] > nums2[j]) j++;
            else i++;
        }
        return -1;
    }
}