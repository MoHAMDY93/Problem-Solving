// Last updated: 6/10/2026, 7:08:41 PM
class Solution {
public:
    int mirrorDistance(int n) {
        auto rev = [&](int n) -> int {
            int ret = 0;
            for (; n ; n /= 10) ret = ret * 10 + n % 10;
            return  ret;
        };
        return abs(n - rev(n));
    }
};