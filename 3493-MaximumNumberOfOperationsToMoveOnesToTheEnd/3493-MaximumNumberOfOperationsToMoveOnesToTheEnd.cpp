// Last updated: 6/10/2026, 7:13:25 PM
class Solution {
public:
    int maxOperations(string s) {
        int cnt = 0 , ans = 0;
        int n = s.size();
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '1') cnt++;
            else {
                if(cnt && s[i-1] != '0') ans += cnt;
            }
        }
        return ans;
    }
};