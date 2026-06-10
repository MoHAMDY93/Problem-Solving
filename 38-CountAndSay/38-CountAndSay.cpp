// Last updated: 6/10/2026, 7:27:35 PM
class Solution {
private:
    string RLE(string s) {
        string out;
        char curr = s[0];
        int cnt = 0;
        for(char c : s) {
            if(c == curr)
                cnt++;
            else {
                out += (cnt + '0');
                out += curr;
                cnt = 1;
                curr = c;
            }
        }
        out += (cnt + '0');
        out += curr;
        return out;
    }
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i=2 ; i<=n ; i++)
            res = RLE(res);
        return res;
    }
};