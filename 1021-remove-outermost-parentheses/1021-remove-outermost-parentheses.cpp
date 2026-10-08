class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        for (auto c : s) {
            if (c == '(') {
                if (!st.empty()) ans.push_back(c);        
                st.push(c);
            } else {
                if (st.size() > 1) ans.push_back(c);
                st.pop();
            }
        }
        return ans;
    }
};