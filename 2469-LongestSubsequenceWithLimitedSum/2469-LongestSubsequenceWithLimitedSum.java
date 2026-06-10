// Last updated: 6/10/2026, 7:16:57 PM
class Solution {
    public int[] answerQueries(int[] nums, int[] q) {
        Arrays.sort(nums);
        for(int i=1 ; i<nums.length ; i++) nums[i] += nums[i-1];
        int ans[] = new int[q.length];
        for(int i=0 ; i<q.length ; i++) {
            var val = q[i];
            int it = Arrays.binarySearch(nums , val);
            if(it < 0) it = (it * -1) - 1;
            else it++;
            ans[i] = it;
        }
        return ans;
    }
}