// Last updated: 6/10/2026, 7:25:11 PM
class Solution {
    public boolean isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return (n == 1);
    }
}