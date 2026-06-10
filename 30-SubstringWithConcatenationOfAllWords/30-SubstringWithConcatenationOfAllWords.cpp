// Last updated: 6/10/2026, 7:27:47 PM
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty()) return res;

        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();
        if (totalLen > s.size()) return res;

        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i <= s.size() - totalLen; i++) {
            string str = s.substr(i, totalLen);
            if (isValid(str, wordCount, wordLen)) {
                res.push_back(i);
            }
        }

        return res;
    }

private:
    bool isValid(const string& s, const unordered_map<string, int>& wordCount, int wordLen) {
        unordered_map<string, int> seen;
        for (int i = 0; i < s.size(); i += wordLen) {
            string word = s.substr(i, wordLen);
            seen[word]++;
        }

        return seen == wordCount;
    }
};
