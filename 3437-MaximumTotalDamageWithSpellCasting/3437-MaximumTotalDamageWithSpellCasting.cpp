// Last updated: 6/10/2026, 7:13:48 PM
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
    unordered_map<int, long long> sum;
    for (int x : power) sum[x] += x;

    vector<int> keys;
    for (auto& [k, _] : sum) keys.push_back(k);
    sort(keys.begin(), keys.end());

    int n = keys.size();
    vector<long long> dp(n);
    dp[0] = sum[keys[0]];

    for (int i = 1; i < n; i++) {
        long long take = sum[keys[i]];
        // find last non-conflicting index
        int j = i - 1;
        while (j >= 0 && keys[i] - keys[j] <= 2) j--;
        if (j >= 0) take += dp[j];
        dp[i] = max(dp[i - 1], take);
    }

    return dp.back();
}

};