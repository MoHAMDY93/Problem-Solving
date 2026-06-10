// Last updated: 6/10/2026, 7:15:01 PM
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans;
        int ones=0 , zeros=0;
        for(char i : s) {
            if(i=='1')
                ones++;
            else
                zeros++;
        }
        while(ones-- > 1)
            ans+='1';
        while(zeros--)
            ans+='0';
        ans+='1';
        return(ans);
    }
};