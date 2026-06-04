class Solution {
public:
    long long count[16][12][12][2][2];
    long long wave[16][12][12][2][2];
    string s;

    long long dp_count(int idx , int prev1 , int prev2 , int start , int small) {
        if (idx == s.size()) return 1;
        auto& ret = count[idx][prev1][prev2][start][small];
        if (~ret) return ret;
        
        ret = 0;
        int ed = small ? 9 : (s[idx] - '0');
        for (int d=0 ; d<=ed ; d++) {
            int nsmall = small || (d < s[idx] - '0');
            int nstart = start || (d > 0);
            
            int nprev1 = nstart ? d : 11;
            int nprev2 = start ? prev1 : 11;

            ret += dp_count(idx+1 , nprev1 , nprev2 , nstart , nsmall);
        }

        return ret;
    }

    long long dp_wave(int idx , int prev1 , int prev2 , int start , int small) {
        if (idx == s.size()) return 0;
        auto& ret = wave[idx][prev1][prev2][start][small];
        if (~ret) return ret;
        
        ret = 0;
        int ed = small ? 9 : (s[idx] - '0');
        for (int d=0 ; d<=ed ; d++) {
            int nsmall = small || (d < s[idx] - '0');
            int nstart = start || (d > 0);
            
            long long inc = 0;
            if (start && prev2 != 11 && prev1 != 11) {
                if ((prev2 < prev1 && prev1 > d) || (prev2 > prev1 && prev1 < d)) {
                    inc = dp_count(idx+1 , d , prev1 , nstart, nsmall);
                }
            }
            
            int nprev1 = nstart ? d : 11;
            int nprev2 = start ? prev1 : 11;

            ret += inc + dp_wave(idx+1 , nprev1 , nprev2 , nstart , nsmall);
        }

        return ret;
    }

    long long get(long long num) {
        if (num < 0) return 0;
        s = to_string(num);
        memset(count , -1 , sizeof(count));
        memset(wave , -1 , sizeof(wave));
        return dp_wave(0 , 11 , 11 , 0 , 0);
    }

    long long totalWaviness(long long num1, long long num2) {
        return get(num2) - get(num1 - 1);
    }
};