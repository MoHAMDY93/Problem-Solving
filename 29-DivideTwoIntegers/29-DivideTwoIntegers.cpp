// Last updated: 6/10/2026, 7:27:48 PM
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        // else if(dividend == INT_MAX && divisor == -1) 
        //     return INT_MIN;
        return dividend / divisor;
    }
};