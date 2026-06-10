// Last updated: 6/10/2026, 7:26:08 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int prev = nums[0] , cnt = 1;
        for(int i=1 ; i<n ; i++) {
            if(nums[i] == prev)
                cnt++;
            else {
                if(cnt > n / 2)
                    return nums[i-1];
                cnt = 1;
            }
            prev = nums[i];
        }
        return nums[n-1];
    }
};