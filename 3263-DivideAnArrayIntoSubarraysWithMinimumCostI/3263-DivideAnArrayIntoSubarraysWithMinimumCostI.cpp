// Last updated: 6/10/2026, 7:14:24 PM
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mn1 = nums[1] ,mn2 = INT_MAX;
        for(int i=2 ; i<nums.size() ; i++) {
            if(nums[i] < mn1) mn2 = mn1 , mn1 = nums[i];
            else if(nums[i] < mn2) mn2 = nums[i];  
        }
        cout << mn1 << ' ' << mn2 << '\n'; 
        return nums[0] + mn1 + mn2;
    }
};