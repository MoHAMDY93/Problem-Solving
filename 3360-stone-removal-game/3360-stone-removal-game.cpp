class Solution {
public:
    bool canAliceWin(int n) {
        bool ans = false;
        int take = 10;
        while (n) {
            if (take > n) return ans;
            n -= (take--);
            ans ^= 1; 
        }
        return ans;
    }
};