// Last updated: 6/10/2026, 7:11:46 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin() , nums.end() , 0) % k;
    }
};