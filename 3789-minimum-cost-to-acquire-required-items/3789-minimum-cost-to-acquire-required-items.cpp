class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (cost1 + cost2 > costBoth) {
            long long mn = min(need1,need2);
            return mn * costBoth + (1LL * need1 - mn) * min(cost1, costBoth) + (1LL * need2 - mn) * min(cost2, costBoth);
        } else {
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }
    }
};