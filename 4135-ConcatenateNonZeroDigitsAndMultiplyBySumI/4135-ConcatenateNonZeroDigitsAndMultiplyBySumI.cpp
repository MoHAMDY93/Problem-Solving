// Last updated: 6/10/2026, 7:09:04 PM
class Solution {
public:
    long long sumAndMultiply(int n) {
        string x;
        long sum = 0;
        while(n) {
            if(n % 10 != 0) x += ('0' + (n % 10));
            sum += n % 10;
            n /= 10;
        }    
        reverse(x.begin() , x.end());
        if(x.empty()) return 0;
        long long X = stoi(x);
        return X * sum;
    }
};