// Last updated: 6/10/2026, 7:23:58 PM
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>> memo(n+1 , vector<int>(m+1 , -1));
        auto dp = [&](int i , int j , auto&& dp) -> int {
            if(i == n && j == m) return 0;
            auto &ret = memo[i][j];
            if(ret != -1) return ret;
            ret = INT_MAX;
            if(i < n) ret = min(ret , (int)(s1[i]) + dp(i+1 , j , dp));
            if(j < m) ret = min(ret , (int)(s2[j]) + dp(i , j+1 , dp));
            // ret = min((int)(s1[i]) + dp(i+1 , j , dp) , (int)(s2[j]) + dp(i , j+1 , dp));
            if(s1[i] == s2[j]) ret = min(ret , dp(i+1 , j+1 , dp));
            return ret;
        };
        return dp(0 , 0 , dp);
    }
};