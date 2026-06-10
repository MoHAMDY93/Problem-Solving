// Last updated: 6/10/2026, 7:22:54 PM
class Solution {
public:
    int fib(int n) {
        int f_p1 = 1 , f_p2 = 0;
        if(n == 0) return f_p2;
        if(n == 1) return f_p1;
        for(int i=2 ; i<=n ; i++) {
            int f_p0 = f_p1 + f_p2;
            f_p2 = f_p1 , f_p1 = f_p0;
        }
        return f_p1;
    }
};