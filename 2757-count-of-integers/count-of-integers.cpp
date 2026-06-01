class Solution {
public:
    int memo[23][2][2][210];
    string s;
    int mn , mx;
    const int MOD = 1e9 + 7; 
    int dp(int idx, int small , int start , int sum) {
        if (idx == s.size()) return sum >= mn;
        auto& ret = memo[idx][small][start][sum];
        if (~ret) return ret;
        ret = 0;

        int ed = small ? 9 : s[idx] - '0';
        for (int d=0 ; d<=ed ; d++) {
            int nstart = start | (d > 0);
            int nsmall = small | (d < (s[idx] - '0'));
            int nsum = sum + d;
            if (nsum <= mx)
                ret = (ret + dp(idx+1 , nsmall , nstart , nsum)) % MOD;    
        }

        return ret;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        // dp[idx][small][start][sum]
        mx = max_sum , mn = min_sum;

        memset(memo , -1 , sizeof(memo));
        s = num2;
        int hi = dp(0 , 0 , 0 , 0);

        memset(memo , -1 , sizeof(memo));
        s = num1;
        int lo = dp(0 , 0 , 0 , 0);
        
        int sum_num1 = 0;
        for (auto c : num1) sum_num1 += (c - '0');
        return (hi - lo + MOD + (mn <= sum_num1 && sum_num1 <= mx)) % MOD;
    }
};