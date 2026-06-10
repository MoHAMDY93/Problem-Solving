// Last updated: 6/10/2026, 7:17:00 PM
class Solution {
public:
    int memo[10][1 << 10][2][2];
    string s;
    int dp(int idx , int mask , int start , int small) {
        if (idx == s.size()) return start == 1;
        auto&ret = memo[idx][mask][start][small];
        if (~ret) return ret;
        int ed = small ? 9 : s[idx] - '0';
        int st = start ? 0 : 1;
        ret = 0;
        if (!start) ret += dp(idx+1 , mask , start , 1);
        for (int d = st ; d<=ed ; d++) {
            if ((mask >> d) & 1) continue;
            int nsmall = small || (d < s[idx] - '0');
            int nstart = start || (d > 0);
            int nmask = mask | (1 << d);
            ret += dp(idx+1 , nmask , nstart , nsmall); 
        }
        return ret;
    }
    int countSpecialNumbers(int n) {
        s = to_string(n);
        memset(memo , -1 , sizeof(memo));
        return dp(0 , 0 , 0 , 0);        
    }
};