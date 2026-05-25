class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        int pre = 0;
        vector<bool> dp(n , false);
        dp[0] = 1;
        for (int i=1 ; i<n ; i++) {
            if (i >= minJump && dp[i - minJump]) pre++;
            if (i > maxJump && dp[i - maxJump - 1]) pre--;
            dp[i] = pre > 0 && s[i] == '0';
        }
        return dp[n-1];
    }
};