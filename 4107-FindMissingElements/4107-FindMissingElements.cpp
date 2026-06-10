// Last updated: 6/10/2026, 7:09:44 PM
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(begin(nums) , end(nums));
        vector<int> ans;
        int curr = nums[0];
        for(auto i : nums) {
            if(i != curr) while(i != curr) ans.push_back(curr++);
            curr++;
        }
        return ans;
    }
};