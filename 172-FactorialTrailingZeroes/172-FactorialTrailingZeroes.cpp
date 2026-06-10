// Last updated: 6/10/2026, 7:26:06 PM
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n) {
            cnt += n / 5;
            n /= 5;
        }
        return cnt;
    }
};