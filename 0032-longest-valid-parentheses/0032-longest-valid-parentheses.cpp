class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> memo(n , -1);
        auto dp = [&](this auto&& dp , int i) -> int {
            if (i >= n) return 0;
            auto&ret = memo[i];
            if (~ret) return ret;
            ret = 0;
            if (s[i] == '(') {
                int inside = dp(i+1);
                int closing_par = i + inside + 1;
                if (closing_par < n && s[closing_par] == ')') {
                    ret = 2 + inside + dp(closing_par + 1);
                }
            } 
            return ret;
        };
        int ans = 0;
        for (int i=0 ; i<n ; i++) ans = max(ans , dp(i));
        return ans;
    }
};