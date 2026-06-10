// Last updated: 6/10/2026, 7:13:41 PM
class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0 ;
        for(auto c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
        }
        if(cnt == 0) return false;
        return true;
    }
};