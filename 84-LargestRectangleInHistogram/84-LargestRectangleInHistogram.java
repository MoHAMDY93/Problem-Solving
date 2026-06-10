// Last updated: 6/10/2026, 7:26:56 PM
class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int[] NSE = new int[n];
        int[] PSE = new int[n];
        Arrays.fill(NSE , n);
        Arrays.fill(PSE , -1);
        Stack<Integer> st = new Stack<>();
        for(int i = n-1 ; i>=0 ; i--) {
            while(!st.empty() && heights[i] <= heights[st.peek()])
                st.pop();
            if(!st.empty())
                NSE[i] = st.peek();
            st.push(i);
        }
        st.clear();
        for(int i=0 ; i<n ; i++) {
            while(!st.empty() && heights[i] <= heights[st.peek()])
                st.pop();
            if(!st.empty())
                PSE[i] = st.peek();
            st.push(i);
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++) {
            int w = NSE[i] - PSE[i] - 1;
            // System.out.print(NSE[i] + " " + PSE[i] + "\n");
            ans = Math.max(ans , w * heights[i]);
        }
        return ans;
    }
}