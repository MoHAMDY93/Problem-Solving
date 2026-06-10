// Last updated: 6/10/2026, 7:24:52 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0 ,  n = s.size();
        for(char c = 'A' ; c <= 'Z' ; c++) {
            int l=0 , r = 0 , cnt = 0;
            while(r < n) {
                if(s[r] != c) cnt++;
                if(cnt > k) {
                    if(s[l] != c) cnt--;
                    l++;
                }
                if(cnt <= k) res = max(res , r - l + 1);
                r++;
            }
        }
        return res;
    }
};