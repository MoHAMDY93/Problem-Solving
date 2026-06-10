// Last updated: 6/10/2026, 7:12:37 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        vector<int> pref(nums.begin() , nums.end()) , suff(nums.begin() , nums.end());
        for(int i=1 ; i<nums.size() ; i++) pref[i] += pref[i-1];
        for(int i=nums.size()-2 ; i>=0 ; i--) suff[i] += suff[i+1];
        int cnt = 0;
        for(int i=0 ; i<nums.size()-1 ; i++) {
            if(abs(pref[i] - suff[i+1]) % 2 == 0) cnt++;
        }
        return cnt;
    }
};