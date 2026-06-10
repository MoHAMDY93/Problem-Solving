// Last updated: 6/10/2026, 7:11:30 PM
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1'000'000'007;
        unordered_map<int,long long> left, right;
        for (int x : nums) right[x]++;
        long long ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            int x = nums[j];
            right[x]--;

            long long need = x * 2LL;
            if (left.count(need) && right.count(need))
                ans = (ans + left[need] * right[need]) % MOD;

            left[x]++;
        }
        return ans;
    }
};