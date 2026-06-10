// Last updated: 6/10/2026, 7:23:10 PM
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int condition = 0;
        for(int i=1 ; i<n ; i++) {
            if(condition == 1){
                if(nums[i] - nums[i-1] < 0) 
                    return false;
            }
            else if(condition == -1){
                if(nums[i] - nums[i-1] > 0) 
                    return false;
            }
            else {
                if(nums[i] - nums[i-1] > 0)
                    condition = 1;
                else if(nums[i] - nums[i-1] < 0)
                    condition = -1;
            }
        }
        return true;
    }
};