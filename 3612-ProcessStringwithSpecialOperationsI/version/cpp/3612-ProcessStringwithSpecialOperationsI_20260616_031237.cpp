// Last updated: 6/16/2026, 3:12:37 AM
1class Solution {
2public:
3    string processStr(string s) {
4        string res;
5        for(auto c : s) {
6            if(c == '*') {
7                if(!res.empty())
8                    res.pop_back();
9            }
10            else if(c == '#')
11                res += res;
12            else if(c == '%')
13                reverse(begin(res) , end(res));
14            else 
15                res.push_back(c);
16        }
17        return res;
18    }
19};