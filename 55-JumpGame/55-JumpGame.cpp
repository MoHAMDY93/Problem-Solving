// Last updated: 6/10/2026, 7:27:25 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        bool ans = true;
        for(int i=n-2 ; i>=0 ; i--) {
            if(nums[i] >= cnt) cnt = 0 , ans = true;
            else ans = false;
            cnt++;
        }
        return ans;
    }
};