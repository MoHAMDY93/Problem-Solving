// Last updated: 6/10/2026, 7:16:02 PM
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> digits;
        for (int i = nums.size()-1 ; i>=0 ; i--) {
            while (nums[i]) {
                digits.push_back(nums[i] % 10);
                nums[i] /= 10;
            }
        } 
        reverse(digits.begin() , digits.end());
        return digits;
    }
};