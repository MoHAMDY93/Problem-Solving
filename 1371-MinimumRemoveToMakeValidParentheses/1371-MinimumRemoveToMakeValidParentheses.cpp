// Last updated: 6/10/2026, 7:21:47 PM
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++) {
            if(s[i] != ')' && s[i] != '(')
                continue;
            if(s[i]=='(') {
                st.push(i);
            } else {
                if(!st.empty()) {
                    st.pop();
                } else {
                    s[i]='0';
                }
            }
        }
        while(!st.empty()) {
            s[st.top()]='0';
            st.pop();
        }
        string ans="";
        for(int i=0;i<n;i++) {
            if(s[i]!='0')
                ans.push_back(s[i]);
        }
        return ans;   
    }
};