class Solution {
public:
    int memo[10][1024][2][2][2];
    string s;
    int dp(int idx , int mask , int ok , int small , int start) {
        if (idx == s.size()) return (int)(start == 1 && ok == 1);
        auto& ret = memo[idx][mask][ok][small][start];
        if (~ret) return ret;

        ret = 0;
        if (start == 0) {
            ret += dp(idx+1 , mask , ok , 1 , 0);
        }
        int ed = small ? 9 : (s[idx] - '0');
        int st = start ? 0 : 1;
        for (int d=st ; d<=ed ; d++) {
            int nstart = start || d > 0;
            int nsmall = small || (d < (s[idx] - '0'));
            int nok = ok || ((mask >> d) & 1);
            int nmask = mask | (1 << d);
            ret += dp(idx+1 , nmask , nok , nsmall , nstart);
        }

        return ret;
    }
    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(memo , -1 , sizeof(memo));
        return dp(0 , 0 , 0 , 0 , 0);
    }
};