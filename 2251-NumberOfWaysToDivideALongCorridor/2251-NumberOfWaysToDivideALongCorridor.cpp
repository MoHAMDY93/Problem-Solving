// Last updated: 6/10/2026, 7:17:55 PM
class Solution {
public:
    int numberOfWays(string s) {
        long long mod = 1000000007;
        int cnt = 0;
        for(char c : s) cnt += c == 'S';
        if(cnt == 0 || cnt & 1) return 0;
        long long ans = 1, bet = 0; 
        int scnt = 0;
        for(auto c : s) {
            if(c == 'S') {
                scnt++;
                if(scnt > 2 && scnt & 1) {
                    ans = (ans * (bet+1)) % mod;
                    bet = 0;
                }
            } else if(scnt >= 2 && scnt % 2 == 0) bet++;
        }
        return ans;
    }
};