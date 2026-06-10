// Last updated: 6/10/2026, 7:19:39 PM
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i=0 ; i+1 < nums.size() ; i++) {
            if (nums[i] > nums[i+1]) cnt++;
        }
        return cnt < 2 && (cnt == 0 ? true : (bool)(nums.back() <= nums[0]));
    }
};