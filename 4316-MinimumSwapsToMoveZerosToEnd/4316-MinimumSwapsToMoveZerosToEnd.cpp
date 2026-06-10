// Last updated: 6/10/2026, 7:07:58 PM
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        for (auto i : nums) zeros += i == 0;
        int cnt = 0;
        for (int i=n-1 ; i>=n-zeros ; i--) cnt += nums[i] != 0;
        return cnt;
    }
};