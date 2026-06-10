// Last updated: 6/10/2026, 7:18:38 PM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a;
        int rem = grid[0][0] % x;
        for (auto v : grid) {
            for (auto i : v) {
                if (i % x != rem) return -1;
                a.push_back(i);
            }
        }
        int n = a.size();
        int mid_idx = n / 2;
        nth_element(a.begin(), a.begin() + mid_idx, a.end());
        int median = a[mid_idx];
        int ans = 0;
        for (auto i : a) ans += abs(i - median) / x;
        return ans;
    }
};