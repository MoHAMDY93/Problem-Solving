// Last updated: 6/10/2026, 7:22:37 PM
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n , false);
        long long curr = 0;
        for(int i=0 ; i<n ; i++) {
            curr = (curr*2LL + nums[i]) % 5;
            ans[i] = (curr == 0);
        }   
        return ans;
    }
};