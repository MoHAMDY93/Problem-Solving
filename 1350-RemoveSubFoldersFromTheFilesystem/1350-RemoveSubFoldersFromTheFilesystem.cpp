// Last updated: 6/10/2026, 7:21:51 PM
class Solution {
public:
    bool check(string a ,  string b) {
        int cnt = 0;
        for(auto c : a) 
            cnt += (c == '/');
        string temp;
        for(auto c : b) {
            cnt -= (c == '/');
            if(cnt < 0) break;
            temp.push_back(c);
        }
        return (temp == a);
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder) , end(folder));
        vector<string> ans;
        for(auto i : folder)
            cout << i << ' ';
        int l=0 , r = 1 , n = folder.size();
        while(r < n) {
            ans.push_back(folder[l]);
            while(folder[r].size() >= folder[l].size()) {
                // string temp = folder[r].substr(0 , (int)folder[l].size());
                if(check(folder[l] , folder[r])) r++;
                else break;
                if(r == n) break;
            }
            l = r;   
        }
        return ans;
    }
};