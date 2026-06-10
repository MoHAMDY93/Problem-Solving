// Last updated: 6/10/2026, 7:17:35 PM
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& a) {
        vector<int> res;
        for(auto i : a) {
            res.push_back(i);
            long long g;
            while(res.size() > 1 && (g = gcd(res.back() , res[res.size()-2])) != 1) {
                long long LCM = 1LL * res.back() * res[res.size()-2] / g;
                res.resize(res.size()-2);
                res.push_back(LCM);
            }
        }
        return res;
    }
};