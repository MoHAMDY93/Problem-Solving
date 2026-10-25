class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cnt = 1;
        for (int i = nums.size()-2 ; i>=0 ; i--) {
            if (nums[i] >= cnt) cnt = 1;
            else cnt++;
        }
        return cnt == 1;
    }
};