// Last updated: 6/10/2026, 7:21:09 PM
class Solution {
    private int lower(int[] a , int k) {
        int l = 0 , r = a.length;
        while(l < r) {
            int m = (l + r) / 2;
            if(a[m] < k) l = m + 1;
            else r = m;
        }
        return l;
    }
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        int n = nums.length;
        int ans[]= new int[n];
        for(int i=0 ; i<n ; i++) ans[i] = lower(sorted , nums[i]);
        return ans;
    }
}