// Last updated: 6/10/2026, 7:25:25 PM
class Solution {
    public boolean isUgly(int n) {
        if(n <= 0) return false;
        int[] primes = {2 , 3 , 5};
        for(var p : primes) {
            while(n % p == 0) n /= p;
        }
        return n == 1;
    }
}