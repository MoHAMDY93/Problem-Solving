// Last updated: 6/10/2026, 7:19:33 PM
class Solution {
public:
    int minOperations(string s) {
        int count1 = 0 , count2 = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            count1 += ((i & 1) ? s[i] == '1' : s[i] == '0');
        }
        return min(count1, n - count1);
    }
};