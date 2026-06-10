// Last updated: 6/10/2026, 7:23:38 PM
class Solution {
public:
    int rotatedDigits(int n) {
        auto check = [&](int x) -> bool {
            int inv = false , ok = false;
            for (; x > 0  ; x /= 10) {
                int d = x % 10;
                if (d == 3 || d == 4 || d == 7) inv = true;
                if (d == 2 || d == 5 | d == 6 || d == 9) ok = true;
            }
            return ok && !inv;
        };
        int cnt = 0;
        for (int i=1 ; i<=n ; i++) {
            // cout << i << ' ' << check(i) << '\n';
            cnt += check(i);
        }
        return cnt;
    }
};