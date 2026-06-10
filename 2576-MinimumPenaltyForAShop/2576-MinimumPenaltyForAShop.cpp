// Last updated: 6/10/2026, 7:16:18 PM
class Solution {
public:
    int bestClosingTime(string cust) {
        int n = cust.size();
        vector<int> pref(n , 0);
        for(int i=0 ; i<n ; i++) {
            if(i == 0) pref[i] += (cust[i] == 'Y' ? 1 : -1);
            else pref[i] = pref[i-1] + (cust[i] == 'Y' ? 1 : -1);
        }
        // for(auto i : pref) cout << i << '\n';
        auto mx = max_element(pref.begin() , pref.end());
        if(*mx > 0) return ((mx - pref.begin()) + 1);
        else return 0;
    }
};