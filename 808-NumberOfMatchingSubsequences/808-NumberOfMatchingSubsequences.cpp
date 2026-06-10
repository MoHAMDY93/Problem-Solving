// Last updated: 6/10/2026, 7:23:35 PM
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<string, int>>> waiting(26);
        for (auto &word : words) {
            waiting[word[0] - 'a'].emplace_back(word, 0);
        }

        int ans = 0;
        for (char c : s) {
            auto current = waiting[c - 'a'];
            waiting[c - 'a'].clear();
            for (auto &[word, idx] : current) {
                idx++;
                if (idx == word.size()) {
                    ans++;
                } else {
                    waiting[word[idx] - 'a'].emplace_back(word, idx);
                }
            }
        }
        return ans;
    }
};