// Last updated: 6/10/2026, 7:16:21 PM
class Solution {
public:
    int pivotInteger(int n) {
        for(int i=1 ; i<=n ; i++) {
            int pref = i * (i+1) / 2;
            int suff = (n * (n+1) / 2) - pref + i;
            // cout << pref << ' ' << suff << '\n'; 
            if(pref == suff) return i;
        }
        return -1;
    }
};