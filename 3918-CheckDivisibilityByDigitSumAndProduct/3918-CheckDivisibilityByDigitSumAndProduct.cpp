// Last updated: 6/10/2026, 7:11:20 PM
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int tmp = n;
        while(tmp) {
            int d = tmp % 10;
            tmp /= 10;
            sum += d;
            product *= d;
        }
        sum += product;
        if(n % sum == 0) return true;
        return false;
    }
};