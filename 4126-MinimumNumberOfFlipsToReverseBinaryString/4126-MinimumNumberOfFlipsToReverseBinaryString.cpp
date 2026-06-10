// Last updated: 6/10/2026, 7:09:38 PM
class Solution {
public:
    int minimumFlips(int n) {
        int ans = 0;
        int lst = log2(n);
        for(int b=0 ; b<=lst ; b++) {
            ans += ((n >> b) & 1) != ((n >> (lst - b)) & 1);
        }
        return ans;
    }
};