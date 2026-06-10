// Last updated: 6/10/2026, 7:22:39 PM
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unsigned long long n = 1 % k , cnt = 1;
        while(cnt <= k) {
            if(n == 0) return cnt;
            n = (n * 10LL + 1LL) % k , cnt++;
        }
        return -1;
    }
};