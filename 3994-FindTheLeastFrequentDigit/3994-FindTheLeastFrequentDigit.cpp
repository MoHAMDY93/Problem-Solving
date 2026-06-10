// Last updated: 6/10/2026, 7:10:39 PM
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int , int> mp;
        int ans = -1 , mn = INT_MAX;
        while(n) {
            int d = n % 10;
            n /= 10;
            mp[d]++;   
        }
        for(auto [d , cnt] : mp) {
            if(cnt < mn) mn = cnt , ans = d;
            if(cnt == mn && d < ans) ans = d;
        }
        return ans;
    }
};