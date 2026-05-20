class Solution {
public:
    long long memo[10][10][2][2];
    string s;
    long long dp(int idx , int cnt , int small , int start) {
        if (idx == s.size()) return start ? cnt : 0;
        auto& ret = memo[idx][cnt][small][start];
        if (~ret) return ret;

        ret = 0;
        int ed = small ? 9 : s[idx] - '0';
        for (int d=0 ; d<=ed ; d++) {
            int nsmall = small || (d < (s[idx] - '0'));
            int nstart = start || d > 0;
            ret += dp(idx+1 , cnt + (d == 1) , nsmall , nstart);
        }   
        return ret;
    }
    int countDigitOne(int n) {
        s = to_string(n);
        memset(memo , -1 , sizeof(memo));
        return dp(0 , 0 , 0 , 0);
    }
};