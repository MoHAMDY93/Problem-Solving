// Last updated: 6/10/2026, 7:24:01 PM
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int b = n & 1;
        while(n) {
            n /= 2;
            int curr = n & 1;
            if(b == curr) return false;
            b = curr;
        } 
        return true;
    }
};