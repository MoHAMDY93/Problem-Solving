// Last updated: 6/10/2026, 7:09:49 PM
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cnta =0  , cntb = 0;
        for(char c : s) cnta += (c == 'a') , cntb += (c == 'b');
        return abs(cnta - cntb);
    }
};