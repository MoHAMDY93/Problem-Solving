// Last updated: 6/10/2026, 7:08:08 PM
class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long prev =0 ;
        long long ans = 0;
        for (auto i : nums) {
            if (i < prev) ans += prev - i;
            prev = i;
        }
        return ans;
    }
};