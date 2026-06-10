// Last updated: 6/10/2026, 7:18:27 PM
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(auto i : nums) maxOR |= i;
        int n = nums.size();
        int ans = 0;
        for(int i=1 ; i<(1 << n) ; i++) {
            int curr = 0;
            for(int j = 0 ; j < n ; j++) {
                if(i & (1 << j)) curr |= nums[j];
            }
            if(curr == maxOR) ans++;
        }
        return ans;
    }
};