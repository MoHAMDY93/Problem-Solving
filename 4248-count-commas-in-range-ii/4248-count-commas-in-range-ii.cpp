class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for (long long val = 3 ; pow(10 , val) <= n ; val++) {
            long long count = min((long long)(9 * pow(10 , val)) , (long long)(n - pow(10 , val) + 1));
            long long commas = val / 3;
            ans +=  count * commas;
        }
        return ans;
    }
};