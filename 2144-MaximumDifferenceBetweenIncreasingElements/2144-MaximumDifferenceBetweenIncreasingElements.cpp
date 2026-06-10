// Last updated: 6/10/2026, 7:18:39 PM
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1 , n = nums.size();
        vector<int> pref(n , nums[0]) , suff(n , nums[n-1]);
        for(int i=1 ; i<n ; i++)    
            pref[i] = min(pref[i-1] , nums[i]);
        for(int i = n-2 ; i>=0 ; i--)
            suff[i] = max(suff[i+1] , nums[i]);
        for(int i=0 ; i<n ; i++) {
            if(suff[i] > pref[i])
                res = max(res , suff[i] - pref[i]);
        }
        return res;
    }
};