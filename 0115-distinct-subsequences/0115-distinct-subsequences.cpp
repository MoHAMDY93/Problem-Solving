class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>> memo(n , vector<int> (m , -1));
        auto dp = [&](this auto&& dp , int i , int j) -> int {
            if (j == m) return 1;
            if (i == n) return 0;
            auto& ret = memo[i][j];
            if (~ret) return ret;
            ret = dp(i+1 , j);;
            if (s[i] == t[j]) ret += dp(i+1 , j+1);
            return ret;
        };
        return dp(0 , 0);
    }
};