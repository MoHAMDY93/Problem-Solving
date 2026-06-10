// Last updated: 6/10/2026, 7:22:00 PM
class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int n = heights.length;
        Stack<Integer> st = new Stack<>();
        int[] ans = new int[n];
        for (int i=n-1 ; i>=0 ; i--) {
            int cnt = 0;
            // see shorter
            while (!st.isEmpty() && heights[i] > st.peek()) {
                cnt++;
                st.pop();
            }
            // see next taller, if exist
            cnt += (st.isEmpty() ? 0 : 1);
            ans[i] = cnt;
            st.push(heights[i]);
        }
        return ans;
    }
}