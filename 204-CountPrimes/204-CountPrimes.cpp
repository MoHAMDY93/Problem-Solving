// Last updated: 6/10/2026, 7:25:47 PM
#define ll long long
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<bool> isPrime(n+1, 1);
        isPrime[0] = isPrime[1] = false;
        for (ll i = 2; i*i <= n; i++) {
            if (isPrime[i]) {
                for (ll j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
};
