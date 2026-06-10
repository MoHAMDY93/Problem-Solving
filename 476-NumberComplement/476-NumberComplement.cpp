// Last updated: 6/10/2026, 7:24:44 PM
class Solution {
public:
    int findComplement(int n) {
        int MSB = log2(n);
        return ((~n) & ((1 << MSB) - 1)) ;
    }
};