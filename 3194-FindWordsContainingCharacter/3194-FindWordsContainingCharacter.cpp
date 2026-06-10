// Last updated: 6/10/2026, 7:14:42 PM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int idx = 0;
        for(string word : words) {
            if(word.find(x) != string::npos)
                ans.push_back(idx);
            idx++;
        }
        return ans;
    }
};