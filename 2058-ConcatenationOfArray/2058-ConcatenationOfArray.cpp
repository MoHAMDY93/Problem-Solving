// Last updated: 6/10/2026, 7:18:56 PM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans((int)nums.size() * 2);
        for(int i=0 ; i<2*nums.size() ; i++) {
            ans[i] = nums[i % nums.size()];
        }
        return ans;
    }
};