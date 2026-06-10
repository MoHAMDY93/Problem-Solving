// Last updated: 6/10/2026, 7:21:28 PM
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i=0 ; i<32 ; i++) {
            // cout << (int)(c & (1 << i)) << ' ';
            if((c >> i) & 1) {
                if(((a >> i) & 1) || ((b >> i) & 1)) continue;
                cnt++;
            } else {
                cnt += ((a >> i) & 1) + ((b >> i) & 1 );
            }
            // cout << cnt << '\n';
        }
        return cnt;
    }
};