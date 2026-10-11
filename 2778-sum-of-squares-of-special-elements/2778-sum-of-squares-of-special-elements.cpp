class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0 , n = nums.size();
        for (int d = 1 ; d*d <= n ; d++) {
            if (n % d == 0) {
                sum += (nums[d - 1] * nums[d - 1]);
                if (n / d != d) {
                    sum += (nums[n / d - 1] * nums[n / d - 1]);
                }
            }
        }
        return sum;
    }
};