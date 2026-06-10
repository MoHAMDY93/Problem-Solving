// Last updated: 6/10/2026, 7:24:29 PM
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>> memo(n+1 , vector<int>(m+1 , -1));
        function<int(int , int)> dp = [&](int i , int j) -> int {
            if (i == n) return m - j;
            if (j == m) return n - i;
            auto& ret = memo[i][j];
            if (~ret) return ret;
            
            if (s[i] == t[j]) ret = dp(i+1 , j+1);
            else {
                ret = min(dp(i+1 , j) , dp(i , j+1)) + 1;
            }

            return ret; 
        };
        int ans = dp(0 , 0);
        
        return ans >= INT_MAX / 4 ? -1 : ans;
    }
};