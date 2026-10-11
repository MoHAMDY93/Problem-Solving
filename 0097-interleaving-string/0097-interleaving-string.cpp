class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size() , m = s2.size() , k = s3.size();
        if (n + m != k) return false;
        vector<vector<int>> memo(n+1 , vector<int> (m+1 , -1));
        auto dp = [&](this auto&& dp , int i , int j) -> int {
            int idx = i + j;
            if (idx == k) return 1;
            auto&ret = memo[i][j];
            if (~ret) return ret;

            ret = 0;
            if (i < n && s1[i] == s3[idx]) ret = max(ret , dp(i+1 , j));
            if (j < m && s2[j] == s3[idx]) ret = max(ret , dp(i , j+1));

            return ret;
        };
        return dp(0 , 0) == 1;
    }
};