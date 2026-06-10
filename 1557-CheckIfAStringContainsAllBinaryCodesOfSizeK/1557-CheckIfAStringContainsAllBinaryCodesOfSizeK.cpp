// Last updated: 6/10/2026, 7:20:53 PM
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for(int i=0 ; i+k-1<s.size() ; i++) {
            string t = s.substr(i , k);
            st.insert(t);
        }
        return st.size() == (1 << k);
    }
};