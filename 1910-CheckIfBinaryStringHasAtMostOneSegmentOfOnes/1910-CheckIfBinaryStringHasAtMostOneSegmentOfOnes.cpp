// Last updated: 6/10/2026, 7:19:28 PM
class Solution {
public:
    bool checkOnesSegment(string s) {
        s.push_back('#');
        // int n = s.size();
        int cnt = 0;
        char prev = s[0];
        for (int i=0 ; i<s.size() ; i++) {
            if (s[i] == prev) continue;
            else {
                if(prev == '1') cnt++;
                prev = s[i];
            }
        }
        return cnt < 2;
    }
};