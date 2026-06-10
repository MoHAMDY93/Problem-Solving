// Last updated: 6/10/2026, 7:25:17 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        else if(n==1){
            return true;
        }
        return n % 3==0 && isPowerOfThree(n/3); 
    }
};