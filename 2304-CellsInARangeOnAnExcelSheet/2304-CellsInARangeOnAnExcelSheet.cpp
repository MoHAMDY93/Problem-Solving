// Last updated: 6/10/2026, 7:17:40 PM
class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for(char c = s[0] ; c<=s[3] ; c++) {
            for(char r = s[1] ; r<=s[4] ; r++) {
                string curr;
                curr.push_back(c);
                curr.push_back(r);
                ans.push_back(curr);
            }
        }
        return ans;
    }
};