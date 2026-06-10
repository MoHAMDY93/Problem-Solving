// Last updated: 6/10/2026, 7:26:50 PM
class Solution {
public:
    int dp[105];
    int numDecodings(string s) {
        memset(dp , -1 , sizeof(dp));
        function<int(int)> calc = [&](int i) {
            if(i == s.size()) return 1;
            if(s[i] == '0') return 0;
            auto &ret = dp[i];
            if(~ret) return dp[i];
            // donn combine only if the current char is not '0'
            ret = calc(i+1);
            // if(s[i] != '0') ret += calc(i+1 , s[i] - '0');
            // combine with prev
            // if(prev != 0 && prev * 10 + (s[i] - '0') <= 26) ret += calc(i+1 , 0);
            if(i+1 < s.size() && (s[i]-'0')*10 + (s[i+1]-'0') <= 26) ret += calc(i+2);
            return ret;
        };
        return calc(0);
    }
};