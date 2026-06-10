// Last updated: 6/10/2026, 7:26:01 PM
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string , int> mp;
        int n = s.size();
        for(int i=0 ; i+9<n ; i++) {
            string t = s.substr(i , 10);
            mp[t]++;
        }
        vector<string> ans;
        for(auto[t , cnt] : mp)
            if(cnt > 1)
                ans.push_back(t);
        return ans;
    }
};