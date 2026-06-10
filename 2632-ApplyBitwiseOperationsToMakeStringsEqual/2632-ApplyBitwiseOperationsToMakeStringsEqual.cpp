// Last updated: 6/10/2026, 7:16:05 PM
class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int n = s.size();
        bool cnt0 = 0 , cnt1 = 0 , diff1 = 0 , diff0 = 0;
        for(int i=0 ; i<n ; i++) {
            cnt0 |= s[i] == '1';
            cnt1 |= t[i] == '1';
            // (s[i] == '0' ? cnt0 : cnt1)++;
            // diff1 += (s[i] == '1' && t[i] == '0');
            // diff0 += (s[i] == '0' && t[i] == '1');
        }
        cout << cnt0 << ' ' << cnt1 << (cnt0 ^ cnt1) << '\n';
        if(cnt0 ^ cnt1) return false;
        return true;
    }
};