// Last updated: 6/10/2026, 7:23:17 PM
class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int ans = 0;
        for(int b=0 ; b<32 ; b++) {
            if((n >> b) & 1) {
                if(~prev) ans = max(ans , b - prev);
                prev = b;
            }
        }
        return ans;
    }
};