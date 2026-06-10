// Last updated: 6/10/2026, 7:15:29 PM
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(long long i=0;  i<60 ; i++) {
            long long num = (long long)num1 - i * (long long)num2;
            if(num < 0) return -1;
            if(num >= i && __builtin_popcountll(num) <= i) return i;
        }
        return -1;
    }
};