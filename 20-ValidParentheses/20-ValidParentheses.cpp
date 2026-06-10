// Last updated: 6/10/2026, 7:28:01 PM
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if(st.empty() || c == ')' && st.top() != '(' || c == '}' && st.top() != '{' || 
                                                   c == ']' && st.top() != '[') 
                    return false;
                else 
                    st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
};