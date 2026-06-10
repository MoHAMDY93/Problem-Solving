// Last updated: 6/10/2026, 7:14:43 PM
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(abs(nums[i] - nums[j]) <= min(nums[i] , nums[j])) mx = max(mx , nums[i] ^ nums[j]);
            }
        }
        return mx;
    }
};