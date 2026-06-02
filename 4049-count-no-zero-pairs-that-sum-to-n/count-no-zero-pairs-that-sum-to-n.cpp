class Solution {
public:
    // idx , carry
    long long memo[16][2][2][2];
    string s;
    long long dp(int idx , int carry , int start1 , int start2) {
        // cout << idx << ' ' << carry << '\n';
        if (idx == s.size()) {
            return carry == 0 && start1 && start2;
        }
        
        auto& ret = memo[idx][carry][start1][start2];
        if (~ret) return ret;

        ret = 0;
        for (int d1 = 0 ; d1 <= 9 ; d1++) {
            if (d1 == 0 && start1) continue;
            for (int d2 = 0 ; d2 <= 9 ; d2++) {
                if (d2 == 0 && start2) continue;
                for (int ncarry = 0 ; ncarry <= 1 ; ncarry++) {
                    int nsum = d1 + d2 + ncarry;
                    if (nsum % 10 != (s[idx] - '0') || nsum / 10 != carry) continue;
                    int nstart1 = start1 || (d1 > 0);
                    int nstart2 = start2 || (d2 > 0);
                    ret += dp(idx+1 , ncarry , nstart1 , nstart2);
                }
            }
        }

        return ret;
    }
    long long countNoZeroPairs(long long n) {
        memset(memo , -1 , sizeof(memo));
        s = to_string(n);
        return dp(0 , 0 , 0 , 0);
    }
};