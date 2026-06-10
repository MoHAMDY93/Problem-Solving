// Last updated: 6/10/2026, 7:10:29 PM
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        const int n = (int)nums.size();
        
        int l = 0;
        long long sumL = nums[0];
        while (l + 1 < n && nums[l] < nums[l + 1]) {
            l++;
            sumL += nums[l];
        }
        
        int r = n - 1;
        long long sumR = nums[n - 1];
        while (r - 1 >= 0 && nums[r - 1] > nums[r]) {
            r--;
            sumR += nums[r];
        }
        
        if (l + 1 < r) return -1;
        if (l + 1 == r) return abs(sumL - sumR);
        
        return min(
            abs((sumL - nums[l]) - sumR),
            abs(sumL - (sumR - nums[r]))
        );
    }
};