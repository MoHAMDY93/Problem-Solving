// Last updated: 6/10/2026, 7:14:01 PM
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(begin(energy) , end(energy));
        for(int i=0 ; i<energy.size() ; i++) {
            if(i - k >= 0) dp[i] = max(dp[i] , dp[i-k] + energy[i]);
        }
        int ans = INT_MIN;
        for(int i = energy.size()-1 ; k > 0 && i >= 0 ; i-- , k--) ans = max(ans , dp[i]);
        return ans;
    }
};