class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int ans = 0;
        for (int i=1 ; i<n ; i++) {
            int diff = prices[i] - prices[i-1];
            ans += (diff > 0 ? diff : 0);
        }
        return ans;
    }
}