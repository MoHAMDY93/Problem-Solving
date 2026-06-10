// Last updated: 6/10/2026, 7:19:04 PM
class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;

        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c2 = a*a + b*b;
                int c = sqrt(c2);

                if (c <= n && c * c == c2) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
