// Last updated: 6/10/2026, 7:17:38 PM
class Solution {
public:
    long long minimalKSum(vector<int>& a, int k) {
        sort(begin(a), end(a));
        // a.erase(unique(begin(a), end(a)), end(a)); // remove duplicates     
        long long sum = 0;
        long long prev = 0;
        for (int x : a) {
            if (k == 0) break;
            int diff = x - prev - 1; 
            if (diff > 0) {
                int take = min(k, diff);
                long long high = prev + take;
                long long low  = prev + 1;
                sum += (high * (high + 1) / 2) - (low * (low - 1) / 2);
                k -= take;
            }
            prev = x;
        }
        
        if (k > 0) {
            long long high = prev + k;
            long long low  = prev + 1;
            sum += (high * (high + 1) / 2) - (low * (low - 1) / 2);
        }
        
        return sum;
    }

};