// Last updated: 6/10/2026, 7:08:12 PM
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int lim = cbrt(n) + 1;
        map<long long , int> mp;
        for (int i=1 ; i<=lim ; i++) {
            for (int j=i+1 ; j<=lim ; j++) {
                long long x = 1LL * i*i*i + j*j*j;
                if (x > n) break;
                mp[x]++; 
            }
        }
        vector<int> ans;
        for (auto [val , cnt] : mp) {
            if (cnt > 1)
                ans.push_back(val);
        }
        return ans;
    }
};