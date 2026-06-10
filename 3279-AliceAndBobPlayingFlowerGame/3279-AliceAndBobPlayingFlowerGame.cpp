// Last updated: 6/10/2026, 7:14:18 PM
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddN = n / 2 + (n & 1) , evenN = n / 2;
        long long oddM = m / 2 + (m & 1) , evenM = m / 2;
        long long res = oddN * evenM + evenN * oddM;
        return res;
    }
};