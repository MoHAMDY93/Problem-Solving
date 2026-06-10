// Last updated: 6/10/2026, 7:20:45 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0 , right = 0 , res = 0 , cnt = 0;
        while(right < n) {
            if(nums[right] == 0) cnt++;
            while(cnt > 1) {
                if(nums[left] == 0) cnt--;
                left++;
            }
            res = max(res , right - left);
            right++;
        }
        return res;
    }
};