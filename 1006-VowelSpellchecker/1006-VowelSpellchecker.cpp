// Last updated: 6/10/2026, 7:22:55 PM
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lowerMap, vowelMap;
        
        auto to_lower = [&](string s) {
            for (auto &c : s) c = tolower(c);
            return s;
        };
        auto devowel = [&](string s) {
            for (auto &c : s) {
                c = tolower(c);
                if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c = '*';
            }
            return s;
        };

        // preprocess wordlist
        for (auto &w : wordlist) {
            string low = to_lower(w);
            if (!lowerMap.count(low)) lowerMap[low] = w;

            string vow = devowel(low);
            if (!vowelMap.count(vow)) vowelMap[vow] = w;
        }

        vector<string> ans;
        for (auto &q : queries) {
            if (exact.count(q)) { ans.push_back(q); continue; }

            string low = to_lower(q);
            if (lowerMap.count(low)) { ans.push_back(lowerMap[low]); continue; }

            string vow = devowel(low);
            if (vowelMap.count(vow)) { ans.push_back(vowelMap[vow]); continue; }

            ans.push_back("");
        }
        return ans;
    }
};
