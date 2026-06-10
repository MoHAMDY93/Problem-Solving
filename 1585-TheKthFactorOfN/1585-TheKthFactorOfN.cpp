// Last updated: 6/10/2026, 7:20:47 PM
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(long long d =1; d*d <= n ; d++) {
            if(n % d == 0) {
                factors.push_back(d);
                if(n / d != d) factors.push_back(n / d);
            }
        }
        factors.push_back(n);
        sort(factors.begin() , factors.end());
        if(k >= factors.size()) return -1;
        return factors[k-1];
    }
};