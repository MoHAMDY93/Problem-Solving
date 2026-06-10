// Last updated: 6/10/2026, 7:21:18 PM
class Solution {
public:
    bool in(char ch) {
        return ch == 'a' || ch == 'b' || ch == 'c';
    }
    int numberOfSubstrings(string s) {
        int n = s.length();
        int r = 0 , l = 0 , cnt = 0;
        map<char , int>mp;
        for(; r<n ; r++) {
            mp[s[r]]++;
            while(mp.size() == 3) {
                cnt += n - r;
                
                mp[s[l]]--;
                if(mp[s[l]] == 0) 
                    mp.erase(s[l]);
                l++;
            }
        }
        return cnt;
    }
};