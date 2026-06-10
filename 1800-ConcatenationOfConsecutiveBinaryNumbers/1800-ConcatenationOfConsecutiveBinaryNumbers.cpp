// Last updated: 6/10/2026, 7:19:59 PM
class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long res = 0;
        int l = 0;
        for(int i=1 ; i<=n ; i++) {
            if((i & (i-1)) == 0) l++;
            res = ((res << l) | i) % MOD;
        }
        return res;
    }
};