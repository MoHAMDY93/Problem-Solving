// Last updated: 6/10/2026, 7:17:44 PM
class Solution {
public:
    int findFinalValue(vector<int>& nums, int origin) {
        sort(nums.begin() , nums.end());
        for(auto i : nums) {
            if(i == origin) origin *= 2;
        }
        return origin;
    }
};