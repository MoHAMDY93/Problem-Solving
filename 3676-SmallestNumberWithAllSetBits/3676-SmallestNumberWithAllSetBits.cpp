// Last updated: 6/10/2026, 7:12:44 PM
class Solution {
public:
    int smallestNumber(int n) {
        return (1 << (int)(log2(n)+1)) - 1;
    }
};