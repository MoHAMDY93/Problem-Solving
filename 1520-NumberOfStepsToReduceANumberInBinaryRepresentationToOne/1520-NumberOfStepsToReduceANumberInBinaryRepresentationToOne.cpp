// Last updated: 6/10/2026, 7:21:02 PM
class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int cnt = 0 , carry = 0;
        for (int i = n-1 ; i>0 ; i--) {
            int curr = (s[i] - '0') + carry;
            if (curr == 0) cnt++ , carry = 0;
            else if (curr == 2) cnt++ , carry = 1;
            else cnt += 2 , carry = 1;
        }
        return cnt + carry;
    }
};