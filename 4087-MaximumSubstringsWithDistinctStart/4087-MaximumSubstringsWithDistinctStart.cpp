// Last updated: 6/10/2026, 7:09:51 PM
class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> st;
        int ans = 0;
        for(auto c : s) st.insert(c);
        return st.size();
    }
};