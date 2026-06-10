// Last updated: 6/10/2026, 7:21:50 PM
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // set<string> st;
        vector<string> ans;
        ans.push_back(words[0]);
        for(auto s : words) {
            auto s1 = s , s2 = ans.back();
            sort(begin(s1) , end(s1));
            sort(begin(s2) , end(s2));
            if(s1 == s2) continue;
            ans.push_back(s);
        }
        return ans;
    }
};