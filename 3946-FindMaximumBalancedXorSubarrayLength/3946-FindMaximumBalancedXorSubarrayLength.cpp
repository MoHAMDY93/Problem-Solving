// Last updated: 6/10/2026, 7:11:07 PM
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
       int ans = 0;
        int n = nums.size();
        int cnt = 0 , even = 0 , odd = 0 , l = 0 , sum = 0;
        map<pair<int , int> , int> mp;
        mp[{0 , 0}] = -1;
        for(int r =0 ; r<n ; r++) {
            sum ^= nums[r];
            if(nums[r] & 1) cnt++;
            else cnt--;
            if(mp.count({sum , cnt})) {
                ans = max(ans , r - mp[{sum , cnt}]);
            } else 
                mp[{sum , cnt}] = r;
        }    
        return ans;
    }
};