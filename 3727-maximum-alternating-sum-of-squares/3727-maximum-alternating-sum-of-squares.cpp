class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (auto& i : nums) {
            if (i < 0) i = -i;
        }
        sort(nums.begin() , nums.end());
        long long ans = 0;
        int l , r;
        for (r = nums.size() - 1 , l = 0 ; l < r ; l++ , r--) {
            ans += (1LL * nums[r] * nums[r] - 1LL * nums[l] * nums[l]);
        }
        if (l == r) ans += (1LL * nums[r] * nums[r]);
        return ans;
    }
};