// Last updated: 6/10/2026, 7:08:24 PM
class Solution {
public:
    int residuePrefixes(string s) {
        int ans = 0;
        set<char> st;
        for(int i=0 ; i<s.size();i++) {
            st.insert(s[i]);
            ans += st.size() == ((i+1)%3); 
        }
        return ans;
    }
};