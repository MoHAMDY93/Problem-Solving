/*
 * @lc app=leetcode id=121 lang=java
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[] suffMax = new int[n];
        for (int i=n-1 ; i >= 0 ; i--) {
            suffMax[i] = prices[i];
            if (i+1 < n) suffMax[i] = Math.max(suffMax[i] , suffMax[i+1]);
        }
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            ans = Math.max(ans , suffMax[i] - prices[i]);
        }
        return ans;
    }
}
// @lc code=end

