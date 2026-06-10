// Last updated: 6/10/2026, 7:25:35 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0) return false;
        int cnt = 0;
        while(n) {
            cnt += (n&1);
            n >>= 1;
        }
        if(cnt == 1) return true;
        return false; 
    }
};