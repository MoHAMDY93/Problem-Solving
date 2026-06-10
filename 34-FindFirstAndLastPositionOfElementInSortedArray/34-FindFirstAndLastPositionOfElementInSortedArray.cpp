// Last updated: 6/10/2026, 7:27:41 PM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        if (it1 == nums.end() || *it1 != target) {
            return {-1, -1};
        }

        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        int start = it1 - nums.begin();
        int end = it2 - nums.begin() - 1;
        return {start, end};
    }
};