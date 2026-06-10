// Last updated: 6/10/2026, 7:23:47 PM
class Solution {
public:
    bool prime(int n) {
        if(n < 2) return false;
        if(n == 2) return right;
        for(int j=2 ; j*j <= n ; j++)
            if(n % j == 0)
                return false;
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left ; i<=right ; i++) {
            int cnt = __builtin_popcount(i);
            ans += prime(cnt);
        }   
        return ans;
    }
};