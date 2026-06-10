// Last updated: 6/10/2026, 7:13:54 PM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        int freq_lower[26] , freq_upper[26];
        for (auto c : word) {
            if ('a' <= c && c <= 'z') freq_lower[c - 'a']++;
            else freq_upper[c - 'A']++; 
        }
        for (int i=0 ; i<26 ; i++) {
            if (freq_lower[i] && freq_upper[i]) cnt++;
        }
        return cnt;
    }
};