class Solution {
public:
    int memo[10][2][2];
    string s;
    vector<int> ds;
    int dp(int idx , int small , int start) {
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
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        for (auto c : digits) ds.push_back(stoi(c));
        for (auto d : ds) cout << d << ' ';
        cout << '\n';
        s = to_string(n);
        cout << s << '\n';
        memset(memo , -1  , sizeof(memo));
        return dp(0 , 0 , 0);
    }
};