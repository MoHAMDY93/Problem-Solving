class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> pref(nums.begin() , nums.end()) , suff(nums.begin() , nums.end());
        for (int i=1 ; i<n ; i++) pref[i] += pref[i-1];
        for (int i = n-2 ; i>=0 ; i--) suff[i] += suff[i+1];
        
        // sum of all elements not enough
        if (pref.back() < x) return -1;
        
        reverse(suff.begin() , suff.end());
        int ans = INT_MAX;
        
        // all from left
        auto it= lower_bound(pref.begin() , pref.end() , x);
        if (*it == x) ans = min(ans , (int)(it - pref.begin() + 1));
        
        // all from right
        it= lower_bound(suff.begin() , suff.end() , x);
        if (*it == x) ans = min(ans , (int)(it - suff.begin() + 1));

        // some from right first then left
        for (int i=0 ; i<n ; i++) {
            if (suff[i] > x) break;
            auto it = lower_bound(pref.begin() , pref.end() , x - suff[i]);
            if (*it != x - suff[i]) continue;
            ans = min(ans , (int)((i + 1) + (it - pref.begin() + 1)));
        }

        // some from left first then right
        for (int i=0 ; i<n ; i++) {
            if (pref[i] > x) break;
            auto it = lower_bound(suff.begin() , suff.end() , x - pref[i]);
            if (*it != x - pref[i]) continue;
            ans = min(ans , (int)((i + 1) + (it - suff.begin() + 1)));
        }


        return (ans == INT_MAX ? -1 : ans);
    }
};