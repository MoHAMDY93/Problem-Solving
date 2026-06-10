// Last updated: 6/10/2026, 7:13:18 PM
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(begin(nums) , end(nums));
        vector<int> ans;
        int prev = -1;
        for(auto i : nums) {
            if(i == prev) ans.push_back(i);
            prev = i;
        }
        return ans;
    }
};