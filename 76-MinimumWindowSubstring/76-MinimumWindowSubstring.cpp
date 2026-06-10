// Last updated: 6/10/2026, 7:27:03 PM
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int need = t.size();
        vector<int> freq(128 , 0);
        for (char c : t) 
            freq[c]++;

        int best_start = 0 , best_len = INT_MAX , l = 0;
        for (int r=0 ; r < n ; r++) {
            if (freq[s[r]] > 0) 
                need--;
            freq[s[r]]--;
            while (need == 0) {
                if (r - l + 1 < best_len) {
                    best_start = l;
                    best_len = r - l  + 1;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0) 
                    need++;
                l++;
            }
        }
        return best_len == INT_MAX ? "" : s.substr(best_start , best_len);
    }
};