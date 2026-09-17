class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> pref(begin(arr) , end(arr));
        int n = arr.size();
        for (int i=1 ; i<n ; i++) pref[i] += pref[i-1];
        int ans = INT_MAX;
        vector<int> shortest(n , INT_MAX);
        map<int , int> mp;
        mp[0] = -1;
        for (int i=0 ; i<n ; i++) {
            if (mp.count(pref[i] - target)) {
                int l = mp[pref[i] - target];
                int len = i - l;
                if (l > 0 && shortest[l] != INT_MAX) {
                    ans = min(ans , len + shortest[l]);
                }
            }
            mp[pref[i]] = i; 
            if (i > 0) shortest[i] = shortest[i-1];
            if (mp.count(pref[i] - target)) {
                int l = mp[pref[i] - target];
                int len = i - l;
                shortest[i] = min(shortest[i] , len);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};