// Last updated: 6/10/2026, 7:20:32 PM
class Solution {
public:
    string thousandSeparator(int n) {
        if(n==0)return to_string(0);
        vector<string>ans;
        while(n) {
            ans.push_back(to_string(n % 1000));
            if(n%1000 < 10 && n>1000) {
                ans.push_back("00");
            }
            else if(n%1000 < 100 && n > 1000) {
                ans.push_back("0");
            }    
            n /= 1000;
        }
        string s;
        for(int i=ans.size()-1 ; i>=0 ; i--) {
            s += ans[i];
            if(i != 0 && (ans[i] != "0" && ans[i] != "00"))
                s += '.';
        }
        return s;
    }
};