// Last updated: 6/10/2026, 7:22:41 PM
class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int MSB = log2(n);
        return ((~n) & ((1 << MSB) - 1)) ;
    }
};