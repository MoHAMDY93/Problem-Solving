class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int[] memo = new int[n];
        Arrays.fill(memo , -1);
        return dp(0, nums, memo);
    }
    private int dp(int i, int[] nums, int[] memo) {
        if (i == nums.length-1) return 0;
        if (memo[i] != -1) return memo[i];
        int ret = Integer.MAX_VALUE / 4;
        for (int j=1 ; j<=nums[i] ; j++) {
            if (i + j >= nums.length) break;
            ret = Math.min(1 + dp(i + j , nums, memo), ret);
        }
        return memo[i] = ret;
    }
}