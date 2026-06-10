// Last updated: 6/10/2026, 7:20:35 PM
class Solution {
public:
    int numSub(string s) {
        long long ans = 0 , cnt = 0;
        char prev = s[0];
        int MOD = 1e9 + 7;
        for(auto c : s) {
            if(c == prev) cnt++;
            else {
                if(prev == '1') ans = (ans + ((cnt * (cnt+1)) / 2) % MOD) % MOD;
                prev = c , cnt = 1;
            }
        }
        if(prev == '1') ans = (ans + ((cnt * (cnt+1)) / 2) % MOD) % MOD;
        return ans;
    }
};