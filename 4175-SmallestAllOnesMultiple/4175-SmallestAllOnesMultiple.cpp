// Last updated: 6/10/2026, 7:08:34 PM
class Solution {
public:
    int minAllOneMultiple(int k) {
        // if(k == 2 || k == 5) return -1;
        unsigned long long n = 1 % k , cnt = 1;
        while(cnt <= k) {
            if(n == 0) return cnt;
            n = (n * 10LL + 1LL) % k , cnt++;
        }
        return -1;
    }
};