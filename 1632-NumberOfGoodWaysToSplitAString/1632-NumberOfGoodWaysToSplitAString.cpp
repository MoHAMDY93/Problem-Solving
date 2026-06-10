// Last updated: 6/10/2026, 7:20:37 PM
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> pref(n) , suff(n);
        unordered_set<char> st1 , st2;
        for(int i=0 , j=n-1; i<n ; i++ , j--) {
            st1.insert(s[i]);
            st2.insert(s[j]);
            pref[i] = st1.size();
            suff[j] = st2.size();
        }
        int ans = 0;
        for(int i=0 ; i<n-1 ; i++) {
            // if(pref[i] == suff[i+1]) cout << i << '\n';
            ans += pref[i] == suff[i+1];
        }
        return ans;  
    }
};