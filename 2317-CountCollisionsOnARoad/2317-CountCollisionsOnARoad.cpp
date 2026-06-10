// Last updated: 6/10/2026, 7:17:29 PM
class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0 , cntR = 0;
        char prev = directions[0];
        for(auto c : directions) {
            if(c == 'S') ans += cntR, prev = c, cntR = 0;
            if(c == 'R') cntR++, prev = 'R';
            if(c == 'L') {
                if(prev == 'S') ans++;
                else if(prev == 'R') ans += cntR + 1 , prev = 'S', cntR = 0;
            }
            // cout << ans <<'\n';
        }
        return ans;
    }
};