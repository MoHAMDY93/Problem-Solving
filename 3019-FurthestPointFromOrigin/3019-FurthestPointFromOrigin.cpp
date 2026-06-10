// Last updated: 6/10/2026, 7:15:04 PM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l_s = 0 , r_s = 0 , tmp = 0;
        for (auto c : moves) {
            if (c == 'L') l_s++;
            else if (c == 'R') r_s++;
            else tmp++;
        }
        return abs(l_s - r_s) + tmp;
    }
};