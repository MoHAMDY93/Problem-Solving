// Last updated: 6/10/2026, 7:22:45 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , cnt = 0 , res = 0 , n = nums.size();
        for(int r=0 ; r<n ; r++) {
            if(nums[r] == 0) cnt++;
            if(cnt > k) {
                if(nums[l] == 0) cnt--;
                l++;
            }
            if(cnt <= k)
                res = max(res , r - l + 1);
        }
        return res;
    }
};