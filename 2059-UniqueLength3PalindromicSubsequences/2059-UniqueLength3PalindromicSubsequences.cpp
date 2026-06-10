// Last updated: 6/10/2026, 7:18:55 PM
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> start(26 , -1), end(26 , -1);
        for(int i=0 ; i<s.size() ; i++) {
            if(~start[s[i] - 'a']) end[s[i]-'a'] = i;
            else start[s[i] - 'a'] = i;
        }
        int ans = 0;
        for(int i=0 ; i<26 ; i++) { 
            if(~start[i] && ~end[i]) {
                cout << start[i] << ' ' << end[i] << '\n'; 
                unordered_set<char> st;
                for(int j = start[i]+1 ; j < end[i] ; j++) st.insert(s[j]);
                ans += st.size();
            }
        }
        return ans;
    }   
};