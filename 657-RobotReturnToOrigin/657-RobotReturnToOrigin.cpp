// Last updated: 6/10/2026, 7:24:10 PM
class Solution {
public:
    bool judgeCircle(string moves) {
        int cntV = 0 , cntH = 0;
        for (char& c : moves) {
            if (c == 'U') cntV++;
            else if (c == 'D') cntV--;
            else if (c == 'R') cntH++;
            else cntH--;
        }
        return cntV == 0 && cntH == 0;
    }
};