// Last updated: 6/10/2026, 7:24:59 PM
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0 , val = 0 , ans;
        int n = nums.size();
        for (int i=0 ; i<n ; i++) {
            sum += nums[i];
            val += i * nums[i];
        }   
        ans = val;
        for (int i=n-1 ; i > 0 ; i--) {
            val += (sum - n * nums[i]);
            ans = max(ans , val);
        }
        return ans;
    }
};