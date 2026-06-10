// Last updated: 6/10/2026, 7:09:47 PM
class Solution {
public:
    bool completePrime(int n) {
        auto isPrime = [&](int n) -> bool {
            if(n <= 1) return false;
            for(int i=2 ; i*i<=n ; i++) {
                if(n % i == 0) return false; 
            }
            return true;
        }; 
        auto tmp = to_string(n);
        int curr = 0;
        for(int i=0 ; i<tmp.size() ; i++) {
            curr = 10 * curr + (tmp[i] - '0');
            if(!isPrime(curr)) return false;
        }
        reverse(tmp.begin() , tmp.end());
        curr = 0;
        for(int i=0 ; i<tmp.size() ; i++) {
            curr = pow(10 , i) * (tmp[i] - '0') + curr;
            if(!isPrime(curr)) return false;
        }
        return true;
    }
};