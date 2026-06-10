// Last updated: 6/10/2026, 7:26:59 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int k = 2;

        if (nums.size() <= 2) return nums.size();
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k; 
    }
};