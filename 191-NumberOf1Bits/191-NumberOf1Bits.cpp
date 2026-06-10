// Last updated: 6/10/2026, 7:25:56 PM
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        for (; n > 0 ; n /= 2) cnt += (n & 1);
        return cnt;
    }
};