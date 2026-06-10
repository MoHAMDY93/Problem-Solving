// Last updated: 6/10/2026, 7:10:34 PM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        return 1LL * k * ((*max_element(nums.begin() , nums.end())) - 
                          (*min_element(nums.begin() , nums.end())));
    }
};