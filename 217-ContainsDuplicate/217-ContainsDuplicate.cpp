// Last updated: 6/10/2026, 7:25:38 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(begin(nums) , end(nums));
        int n = nums.size();
        for(int i=1 ; i<n ; i++) {
            if(nums[i] == nums[i-1]) return true;
        }
        return false;
    }
};