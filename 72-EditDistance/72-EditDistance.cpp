// Last updated: 6/10/2026, 7:27:09 PM
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>> memo(n+1 , vector<int> (m+1 , -1));
        auto dp = [&](int i , int j , auto&& dp) -> int {
            if(i == n) return m - j;
            if(j == m) return n - i;
            // if(i == n && j == m) return 0;
            auto &ret = memo[i][j];
            if(ret != -1) return ret;
            ret = INT_MAX;
            // matched
            if(s1[i] == s2[j]) ret = dp(i+1 , j+1 , dp);
            ret = min({ret , 1 + dp(i+1 , j , dp) , 1 + dp(i , j+1 , dp) , 1 + dp(i+1 , j+1 , dp)});
            return ret;
        };
        return dp(0 , 0 , dp);
    }
};