
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // 1. Precompute bonus using divisor counting
        int maxi = 0;
        for (auto& it : items)
            maxi = max(maxi, it[0]);

        vector<int> fac(maxi + 1);

        for (auto& it : items) {
            int x = it[0];

            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    fac[d]++;
                    if (d != x / d)
                        fac[x / d]++;
                }
            }
        }

        vector<int> bonus(n);
        for (int i = 0; i < n; i++)
            bonus[i] = fac[items[i][0]] - 1;

        // 2. Contiguous DP allocation
        vector<vector<array<int, 2>>> memo(
            n, vector<array<int, 2>>(budget + 1, {-1, -1})
        );

        auto dp = [&](this auto&& dp, int idx, int cost, int buy) -> int {
            if (idx == n || cost == 0)
                return 0;

            auto& ret = memo[idx][cost][buy];
            if (ret != -1)
                return ret;

            ret = 0;

            // Skip current item
            ret = max(ret, dp(idx + 1, cost, 0));

            // Buy current item
            if (items[idx][1] <= cost) {
                int ncnt = buy ? 1 : 1 + bonus[idx];

                ret = max(
                    ret,
                    ncnt + dp(idx, cost - items[idx][1], 1)
                );
            }

            return ret;
        };

        return dp(0, budget, 0);
    }
};
