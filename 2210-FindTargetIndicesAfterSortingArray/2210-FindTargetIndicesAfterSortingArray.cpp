// Last updated: 6/10/2026, 7:18:13 PM
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(begin(nums) , end(nums));
        vector<int>ans;
        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i] == target)
                ans.push_back(i);
        }
        return ans;
    }
};