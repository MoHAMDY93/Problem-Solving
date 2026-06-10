// Last updated: 6/10/2026, 7:27:05 PM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            int j = i;
            while (j > 0 && nums[j - 1] > val) {   // keep going left
                nums[j] = nums[j - 1];             // shift bigger element right
                --j;
            }
            nums[j] = val;                         // insert in its place
        }
    }
};