// Last updated: 6/10/2026, 7:15:14 PM
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long even_best = (nums[0] % 2 == 0 ? nums[0] : INT_MIN);
        long long odd_best  = (nums[0] % 2 != 0 ? nums[0] : INT_MIN);

        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                // nums[i] is even
                even_best = max(even_best + nums[i],
                                odd_best + nums[i] - x);
            } else {
                // nums[i] is odd
                odd_best = max(odd_best + nums[i],
                               even_best + nums[i] - x);
            }
        }

        return max(even_best, odd_best);
    }
};