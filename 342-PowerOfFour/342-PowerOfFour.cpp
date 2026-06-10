// Last updated: 6/10/2026, 7:25:08 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        if(__builtin_popcount(n) == 1 && (int)log2(n) % 2 == 0) return true;
        return false;
    }
};