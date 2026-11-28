class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n+1);
        for (auto&v : items) {
            freq[v[0]]++;
        }
        vector<int> bonus(n+1, 0);
        for (int i=1 ; i<=n ; i++) {
            for (int j = i ; j<=n ; j+=i) {
                bonus[i] += freq[j];
            }
            bonus[i]--;
        }
        sort(begin(items), end(items), [](const auto& A, const auto& B) {
            return A[1] < B[1];
        });
        int mn = items[0][1];
        int ans = 0;
        for (auto& item : items) {
            int fac = item[0], price = item[1];
            if (price > mn * 2) continue;
            int take = min(bonus[fac], budget / price);
            ans += 2*take;
            budget -= take*price;
        }
        ans += budget / mn;
        return ans;
    }
};