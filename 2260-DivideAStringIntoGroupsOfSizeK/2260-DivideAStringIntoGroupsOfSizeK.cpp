// Last updated: 6/10/2026, 7:17:52 PM
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string str;
        int cnt = 0;
        for(char c : s) {
            if(cnt == k) {
                ans.push_back(str);
                str.clear();
                cnt = 1;
            } else {
                cnt++;
            }
            str.push_back(c);
        }
        while(cnt++ < k) {
            str.push_back(fill);
        }
        ans.push_back(str);
        return ans;
    }
};