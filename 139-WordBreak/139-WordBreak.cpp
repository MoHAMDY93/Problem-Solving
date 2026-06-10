// Last updated: 6/10/2026, 7:26:30 PM
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st;
        for(auto word : wordDict) st.insert(word);
        vector<vector<int>> memo(n, vector<int> (n , -1));
        function<int(int , int)> dp = [&](int i , int prev) {
            if(i == n) return (int)(prev == n);
            auto &ret = memo[i][prev];
            if(~ret) return ret;
            // skip
            ret = dp(i+1 , prev);
            // take if possible
            if(st.count(s.substr(prev , i-prev+1))) ret += dp(i+1 , i+1);
            // cout << ret << '\n';
            return ret;
        };
        return dp(0 , 0) > 0;
    }
};