// Last updated: 6/10/2026, 7:11:15 PM
class Solution {
public:
    string processStr(string s) {
        string res;
        for(auto c : s) {
            if(c == '*') {
                if(!res.empty())
                    res.pop_back();
            }
            else if(c == '#')
                res += res;
            else if(c == '%')
                reverse(begin(res) , end(res));
            else 
                res.push_back(c);
        }
        return res;
    }
};