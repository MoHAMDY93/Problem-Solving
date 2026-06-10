// Last updated: 6/10/2026, 7:21:29 PM
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=n-1 ; i>=0 ; i--) {
            bool ok = true;
            int tmp = i;
            while(tmp) {
                if(tmp % 10 == 0){ 
                    ok = false;
                    break;
                }
                tmp /= 10;
            }
            if(ok) {
                int tmp2 = n - i;
                while(tmp2) {
                    if(tmp2 % 10 == 0) {
                        ok = false;
                        break;
                    }
                    tmp2 /= 10;
                }
            }
            if(ok) return {n - i , i};
        }
        return {};
    }
};