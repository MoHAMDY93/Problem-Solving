// Last updated: 6/10/2026, 7:12:30 PM
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> bonus(n);
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (i == j) continue;
                bonus[i] += (items[j][0] % items[i][0] == 0);
            }
        }
        vector<int> dp(budget + 1 , 0);
        for (int i=0 ; i<n ; i++) {
            int price = items[i][1];
            int inc = bonus[i] + 1;
            vector<int> next_dp = dp;
            for (int w = budget ; w>=price ; w--) {
                next_dp[w] = max(next_dp[w] , dp[w - price] + inc);
            }
            for (int w = price ; w<=budget ; w++) {
                next_dp[w] = max(next_dp[w] , next_dp[w - price] + 1);
            }
            dp = move(next_dp);
        }
        int mx = 0;
        for (int w=0 ; w<=budget ; w++) {
            mx = max(mx , dp[w]);
        }
        return mx;
    }
};