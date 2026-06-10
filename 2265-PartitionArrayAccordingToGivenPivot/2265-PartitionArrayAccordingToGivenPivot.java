// Last updated: 6/10/2026, 7:17:53 PM
class Solution {
    private void swap(int[] a , int i , int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public int[] pivotArray(int[] nums, int pivot) {
        int n=nums.length;
        int m=0;
        int[] ans=new int[n];
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                ans[m]=nums[i];
                m++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                ans[m]=nums[i];
                m++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                ans[m]=nums[i];
                m++;
            }
        }
        return ans;
    }

}