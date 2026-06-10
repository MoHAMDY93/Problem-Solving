// Last updated: 6/10/2026, 7:27:26 PM
class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if(exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        double res = 1.0;
        while(exp > 0) {
            if(exp & 1) {
                res *= x;
            }
            x *= x;
            exp >>= 1;
        }
        return res;
    }
};