// Last updated: 6/10/2026, 7:23:59 PM
class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 1 , ans = 0 , prev = 0;
        for(int i=1 ; i<s.size() ; i++) {
            if(s[i] != s[i-1]) {
                ans += min(prev , cur);
                prev = cur;
                cur = 1;
            } else 
                cur++;
        }
        return ans + min(cur , prev);
    }
};