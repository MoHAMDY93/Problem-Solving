// Last updated: 6/10/2026, 7:18:58 PM
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>a;
        for(int i : nums)
            a.push_back(nums[i]);
        return a;
    }
};