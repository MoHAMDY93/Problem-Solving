// Last updated: 6/10/2026, 7:13:58 PM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> pos(128 , -1);
        int n = word.size();
        for (int i=0 ; i<n ; i++) {
            char c = word[i];
            if ('a' <= c && c <= 'z') pos[c] = i;
            else if(pos[c] == -1) pos[c] = i;
        }
        int ans = 0;
        for (int i=0 ; i<26 ; i++) {
            if (~pos[i + 'a'] && ~pos[i + 'A'] && pos[i + 'a'] < pos[i + 'A']) ans++;
        }
        return ans;
    }
};