// Last updated: 6/10/2026, 7:24:56 PM
class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        vector<int>cnt(52);
        for(char c : s) {
            if(isupper(c))
                cnt[c - 'A' + 25]++;
            else 
                cnt[c - 'a']++;
        }
        bool flag = false;
        for(int i : cnt) {
            if(i % 2 == 1) flag = true;
            if(i & 1) ans += (i-1);
            else ans += i;
        }
        if(flag)
            ans++;
        return ans;
    }
};