// Last updated: 6/10/2026, 7:20:40 PM
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<int> heights(m , 0);
        int ans = 0;
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                heights[j] = (mat[i][j] ? heights[j]+1 : 0);
            }
            stack<int> st;
            vector<int> sum(m+1 , 0);
            for(int j=0 ; j<m ; j++) {
                while(!st.empty() && heights[st.top()] >= heights[j]) {
                    st.pop();
                }
                if(!st.empty()) {
                    int prev = st.top();
                    sum[j] = sum[prev] + heights[j] * (j - prev);
                } else {
                    sum[j] = heights[j] * (j + 1);
                }
                st.push(j);
                ans += sum[j];
            }
        }
        return ans;
    }
};