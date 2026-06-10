// Last updated: 6/10/2026, 7:17:13 PM
class Solution {
public:
    int countHousePlacements(int n) {
        long long mod = 1e9 + 7;
        long long prev1 = 1 , prev2 = 2;
        for (int i = 2 ; i<=n ; i++) {
            long long curr = (prev1 + prev2) % mod;
            prev1 = prev2;
            prev2 = curr;
        }
        long long ans = (prev2 * prev2) % mod;
        return ans;
    }
};