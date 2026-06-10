// Last updated: 6/10/2026, 7:07:53 PM
class Solution {
public:
    int digitFrequencyScore(int n) {
        int freq[10] = {0};
        for ( ; n ; n /= 10) freq[n % 10]++;
        int ans = 0;
        for (int i=1 ; i<=9 ; i++) ans += i * freq[i];
        return ans;
    }
};