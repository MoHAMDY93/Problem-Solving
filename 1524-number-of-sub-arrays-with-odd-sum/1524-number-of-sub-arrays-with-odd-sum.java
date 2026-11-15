class Solution {
    public int numOfSubarrays(int[] arr) {
        int n = arr.length;
        int os = 0 , es = 0 , sum = 0, ans = 0;
        int MOD = 1_000_000_007;
        for (int i : arr) {
            sum += i;
            sum %= 2;
            if (sum == 1) {
                ans += es + 1;
                os++;
            } else {
                ans += os;
                es++;
            }
            ans %= MOD;
        }
        return ans;
    }
}