// Last updated: 6/10/2026, 7:12:24 PM
class Solution {
public:
    int maxDifference(string s) {
        int odd = 0 , even = INT_MAX;
        int cnt = 0;
        sort(begin(s) , end(s));
        char prev = s[0];
        for(char c : s) {
            if(c == prev)   cnt++;
            else {
                if(cnt & 1)
                    odd = max(odd , cnt);
                else 
                    even = min(even , cnt);
                prev = c , cnt = 1;
            }
        }
        if(cnt & 1)
            odd = max(odd , cnt);
        else 
            even = min(even , cnt);
        return odd - even;
    }
};