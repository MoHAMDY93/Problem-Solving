// Last updated: 6/10/2026, 7:15:24 PM
class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(begin(nums) , end(nums));
        int n = nums.size();
        for(int i=0 ; i<n ; i++)
            if(i+1 < n && nums[i] != i+1) return false;
        return n >= 2 && nums[n-1] == n-1 && nums[n-2] == n-1;
    }
};