// Last updated: 6/10/2026, 7:10:24 PM
class Solution {
    public int longestSubsequence(int[] nums) {
        int xor = 0;
        Set<Integer> st = new HashSet<>();
        for(int num : nums) {
            xor ^= num;
            st.add(num);
        }
        if(xor != 0) return nums.length;
        if(st.size() == 1 && nums[0] == 0) return 0;
        return nums.length - 1;
    }
}