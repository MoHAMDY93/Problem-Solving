class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        bool inc = false , dec = false;
        int cnt = 1, ans = 1;
        for (int i=1 ; i<nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                dec = false;
                if (inc) cnt++;
                else inc = true, cnt = 2;
            } else if (nums[i] < nums[i-1]) {
                inc = false;
                if (dec) cnt++;
                else dec = true, cnt = 2;
            } else {
                cnt = 1, inc = false, dec = false;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};