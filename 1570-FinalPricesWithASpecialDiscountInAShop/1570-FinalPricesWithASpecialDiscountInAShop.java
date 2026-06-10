// Last updated: 6/10/2026, 7:20:50 PM
class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        Stack<Integer> stack = new Stack<>();
        for(int i=n-1 ; i>=0 ; i--) {
            while(!stack.empty() && prices[i] < stack.peek())
                stack.pop();
            if(!stack.empty())
                ans[i] = stack.peek();
            stack.push(prices[i]);
        }   
        int[] res = new int[n];
        for(int i=0 ; i<n ; i++) {
            if(ans[i] == -1) res[i] = prices[i];
            else res[i] = prices[i] - ans[i];
        }
        return res;
    }
}