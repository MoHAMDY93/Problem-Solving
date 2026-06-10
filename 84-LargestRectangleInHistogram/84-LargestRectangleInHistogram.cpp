// Last updated: 6/10/2026, 7:27:01 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;
        heights.push_back(0);
        for(int i=0 ; i<=n ; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()]; st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans , h * width);
            }
            st.push(i);
        }
        return ans;
    }
};