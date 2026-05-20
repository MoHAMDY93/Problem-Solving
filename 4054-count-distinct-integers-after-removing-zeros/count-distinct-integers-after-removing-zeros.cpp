class Solution {
public:
    long long memo[16][2][2];
    string s;
    vector<int> ds;
    long long dp(int idx , int small , int start) {
        if (idx == s.size()) return start == 1;
        auto& ret = memo[idx][small][start];
        if (~ret) return ret;

        ret = 0;
        if (start == 0) {
            ret += dp(idx + 1, 1, 0);
        }
        int ed = small ? 9 : (s[idx] - '0');
        for (auto d : ds) {
            if (d > ed) continue;
            int nsmall = small || (d < (s[idx] - '0'));
            int nstart = start || (d != 0);
            ret += dp(idx+1 , nsmall , nstart);
        }

        return ret;
    }
    long long countDistinct(long long n) {
        for (int i=1 ; i<=9 ; i++) ds.push_back(i);
        s = to_string(n);
        memset(memo , -1 , sizeof(memo));
        return dp(0 , 0 , 0);
    }
};