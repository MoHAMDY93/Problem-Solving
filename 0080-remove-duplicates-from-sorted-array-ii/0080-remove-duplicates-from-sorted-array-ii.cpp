class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), r , w;
        bool duplicate = false;
        for (r = 1 , w = 1 ; r < n ; r++) {
            if (nums[r] != nums[r-1]) nums[w++] = nums[r] , duplicate = false;
            else if (nums[r] == nums[r-1] && !duplicate) nums[w++] = nums[r] , duplicate = true;
        }
        return w;
    }
};