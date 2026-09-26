class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        unordered_map<string , string> mp;
        for (auto v : knowledge) {
            mp[v[0]] = v[1];
        } 
        for (int i=0 ; i<s.size() ; i++) {
            char c = s[i];
            if (c == '(') {
                string key;
                while (s[i+1] != ')') key.push_back(s[i+1]) , i++;
                // cout << key << endl;
                if (mp.count(key)) ans.append(mp[key]);
                else ans.push_back('?');
            } else if (c != ')')
                ans.push_back(c);
        }   
        return ans;
    }
};