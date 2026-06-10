// Last updated: 6/10/2026, 7:16:14 PM
class Solution {
public:
    bool isPrime(int n) {
        if(n < 2)
            return false;
        if(n == 2)
            return true;
        for(int i = 2 ; i*i <=n ; i++) {
            if(n % i == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes;
        for(int i = left ; i <= right ; i++) {
            if(isPrime(i))
                primes.push_back(i);
        }
        vector<int>ans = {INT_MAX , INT_MAX};
        if(primes.size() < 2) {
            ans = {-1 , -1};
        }
        else {
            int Min = INT_MAX;
            for(int i=0 ; i<primes.size()-1 ; i++) {
                if(primes[i+1] - primes[i] < Min) {
                    Min = primes[i+1] - primes[i];
                    ans = {primes[i] , primes[i+1]};
                }
            }
        }
        return ans;
    }
};