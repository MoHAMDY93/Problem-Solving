class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for (long long val = 3 ; pow(10 , val) < n ; val++) {
            int count = min((long long)(9 * pow(10 , val)) , (long long)(n - pow(10 , val)));
            int commas = val / 3;
            ans +=  count * commas;
            // cout << count << ' ' << commas << '\n';
        }
        return ans + (n >= 1000);
    }
};