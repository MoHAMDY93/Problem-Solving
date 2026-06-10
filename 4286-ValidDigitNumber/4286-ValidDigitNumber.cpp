// Last updated: 6/10/2026, 7:08:03 PM
class Solution {
public:
    bool validDigit(int n, int x) {
        bool ok1 = false , ok2 = false;
        while (n >= 10) {
            if (n % 10 == x) ok1 = true; 
            n /= 10;
        }
        if (n != x) ok2 = true;
        return ok1 && ok2;
    }
};