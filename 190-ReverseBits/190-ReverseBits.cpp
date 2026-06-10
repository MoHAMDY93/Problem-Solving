// Last updated: 6/10/2026, 7:25:58 PM
class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int b=0 ; b < 32 ; b++) {
            ans <<= 1;
            ans += ((n >> b) & 1);
        }
        return ans;
    }
};