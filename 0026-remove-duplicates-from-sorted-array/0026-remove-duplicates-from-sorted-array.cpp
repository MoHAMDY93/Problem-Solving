class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), r , w;
        for (r = 1 , w = 1 ; r < n ; r++) {
            if (nums[r] != nums[r-1]) nums[w++] = nums[r];
        }
        return w;
    }
};