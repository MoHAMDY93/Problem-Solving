// Last updated: 6/10/2026, 7:28:28 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int MAX = 0;
        int l = 0 , r = 0;
        int cnt = 0;
        unordered_set<char>st;
        while(r < n) {
            if(st.find(s[r]) != st.end()){
                st.erase(s[l++]);
                cnt--;
            }
            else {
                st.insert(s[r++]);
                cnt++;
                MAX = max(MAX , cnt);
            }
        }
        // cout<<MAX<<endl;
        return MAX;
    }
};