// Last updated: 6/10/2026, 7:28:31 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int> seen;
        for (int i=0 ; i<n ; i++) {
            if (seen.count(target - nums[i])) return {i , seen[target - nums[i]]};
            seen[nums[i]] = i;
        }
        return {};
    }
};