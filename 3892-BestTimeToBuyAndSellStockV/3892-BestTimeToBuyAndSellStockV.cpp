// Last updated: 6/10/2026, 7:11:24 PM
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> memo(n , vector<vector<long long>>(k+1 , vector<long long>(3 , -1)));
        function<long long(int , int , int)> dp = [&](int i , int curr , int flag) {
            if(i == n || curr == 0) return flag == 0 ? 0LL : LLONG_MIN / 2;
            auto &ret = memo[i][curr][flag];
            if(~ret) return ret;
            // skip 
            ret = dp(i+1 , curr , flag);

            // start a transaction if flag = 0
            if(flag == 0) ret = max({ret , -prices[i] + dp(i+1 , curr , 1) , prices[i] + dp(i+1 , curr , 2)});
            if(flag == 1) ret = max(ret , prices[i] + dp(i+1 , curr-1 , 0));
            if(flag == 2) ret = max(ret , -prices[i] + dp(i+1 , curr-1 , 0));

            return ret;
        };
        return dp(0 , k , 0);
    }
};