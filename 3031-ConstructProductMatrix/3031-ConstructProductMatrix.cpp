// Last updated: 6/10/2026, 7:15:02 PM
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        vector<int> a;
        for (auto &row : grid) {
            for (auto x : row)
                a.push_back(x);
        }
        int n = a.size();
        vector<long long> pref(n, 1), suff(n, 1);
        for (int i = 1; i < n; i++) {
            pref[i] = (pref[i-1] * a[i-1]) % MOD;
        }
        for (int i = n-2; i >= 0; i--) {
            suff[i] = (suff[i+1] * a[i+1]) % MOD;
        }
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> ans(N, vector<int>(M));
        for (int i = 0; i < n; i++) {
            int val = (pref[i] * suff[i]) % MOD;
            ans[i / M][i % M] = val; 
        }
        return ans;
    }
};