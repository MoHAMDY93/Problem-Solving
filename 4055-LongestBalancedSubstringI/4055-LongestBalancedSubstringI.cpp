// Last updated: 6/10/2026, 7:10:08 PM
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            int freq[26] = {0};
            int cnt = 0 , cntMax = 0 , maxi = 0;
            for (int j=i ; j<n ; j++) {
                int f = ++freq[s[j] - 'a'];
                if (f == 1) cnt++;
                if (f > maxi) {
                    maxi = f;
                    cntMax = 1;
                } else if (f == maxi)
                    cntMax++;
                
                if (cnt == cntMax) 
                    ans = max(ans , j - i + 1);
            }
        }
        return ans;
    }
};