class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> memo(n , vector<int> (n+1 , -1));
        auto dp = [&](this auto&& dp , int i , int cnt) -> int {
            if (i == n) return (cnt == 0);
            if (cnt > n - i) return 0;
            auto& ret = memo[i][cnt];
            if (~ret) return ret;
            ret = 0;
            if (s[i] == '(') ret = max(ret , dp(i+1 , cnt+1));
            else if (s[i] == ')') {
                if (cnt == 0) return 0;
                ret = max(ret , dp(i+1 , cnt-1));
            }
            else {
                ret = max({ret , dp(i+1 , cnt+1) , dp(i+1 , cnt)});
                if (cnt > 0) ret = max(ret , dp(i+1 , cnt - 1));
            }
            return ret;
        };
        return dp(0 , 0) > 0;
    }
};