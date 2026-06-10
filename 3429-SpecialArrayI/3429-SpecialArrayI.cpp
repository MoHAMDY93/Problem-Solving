// Last updated: 6/10/2026, 7:13:53 PM
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int l = 0, r = 1 , n = nums.size();
        while(r < n) {
            if(nums[r++] % 2 == nums[l++] % 2)
                return false;
        }
        return true;
    }
};