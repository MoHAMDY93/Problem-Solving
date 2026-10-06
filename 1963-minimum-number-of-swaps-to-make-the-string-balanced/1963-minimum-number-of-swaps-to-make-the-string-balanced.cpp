class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0 , ans = 0 , skip = 0;
        for (auto c : s) {
            if (c == '[') cnt++;
            else {
                if (!cnt) ans++;
                else cnt--;
            }
        }
        return (ans + 1) / 2;
    }
};