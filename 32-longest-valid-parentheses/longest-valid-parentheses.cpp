class Solution {
public:
    int memo[30005];
    string st;
    int n;
    int dp(int idx) {
        if (idx >= n-1) return 0;
        auto& ret = memo[idx];
        if (~ret) return ret;
        ret = 0;
        if (st[idx] == '(') {
            int inside_len = dp(idx+1);
            int cand_match = idx + 1 + inside_len;
            if (cand_match < n && st[cand_match] == ')') {
                ret = 2 + inside_len + dp(cand_match + 1);
            } 
        }
        return ret;
    }
    int longestValidParentheses(string s) {
        st = s;
        n = s.size();
        memset(memo , -1 , sizeof(memo));
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            ans = max(ans , dp(i));
        }
        return ans;
    }
};