// Last updated: 6/10/2026, 7:14:05 PM
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26) , pref(1 , 0) , a;
        for(char c : word)
            freq[c - 'a']++;
        for(int i : freq) {
            if(i) a.push_back(i);
        }
        int m = a.size();
        sort(a.begin() , a.end());
        for(int i : a) {
            pref.push_back(i + pref.back());
        }
        int ans = INT_MAX;
        for(int i=0 ; i<m ; i++) {
            int it = upper_bound(a.begin() , a.end() , a[i] + k) - a.begin();
            int curr = pref[i];
            int rightSum = pref[m] - pref[it];
            curr += (rightSum - ((a[i] + k) * (m - it)));
            ans = min(ans , curr);
        }
        return ans;
    }
};