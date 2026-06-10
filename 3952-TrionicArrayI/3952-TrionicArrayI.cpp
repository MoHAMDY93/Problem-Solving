// Last updated: 6/10/2026, 7:11:06 PM
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1 , n = nums.size();
        int cnt = 0;
        for(; i<n ; i++) {
            if(nums[i] == nums[i-1]) return false;
            if(nums[i] < nums[i-1]) break;
            cnt = 1;
        }
        if(cnt == 0) return false;
        for(; i<n ; i++) {
            if(nums[i] == nums[i-1]) return false;
            if(nums[i] > nums[i-1]) break;
            cnt = 2;
        }
        if(cnt == 1) return false;
        for(; i<n ; i++) {
            if(nums[i] == nums[i-1]) return false;
            if(nums[i] < nums[i-1]) break;
            cnt = 3;
        }
        return i == n && cnt == 3;
    }
};