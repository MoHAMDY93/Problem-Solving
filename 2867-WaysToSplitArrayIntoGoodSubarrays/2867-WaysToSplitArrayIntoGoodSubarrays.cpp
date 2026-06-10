// Last updated: 6/10/2026, 7:15:21 PM
class Solution {
public:
    const long long MOD = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long ans = 1;
        long long cnt = 1;
        int i = 0;
        while(i < nums.size() && nums[i] == 0) i++;
        if(i == nums.size()) return 0;
        for(; i<nums.size() ; i++) {
            if(nums[i] == 0) cnt++;
            else {
                ans = (ans * cnt) % MOD;
                cnt = 1;
            }
        }
        return ans;
    }
};