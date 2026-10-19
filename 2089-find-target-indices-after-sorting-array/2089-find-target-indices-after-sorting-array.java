class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        int less = 0 , cnt = 0;
        for (int i=0 ; i<n ; i++) {
            less += (nums[i] < target ? 1 : 0);
            cnt += (nums[i] == target ? 1 : 0);
        }
        for (int i=0 ; i<cnt ; i++) 
            ans.add(less + i);
        
        return ans;
    }
}