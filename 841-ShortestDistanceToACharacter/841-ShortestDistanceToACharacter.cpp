// Last updated: 6/10/2026, 7:23:25 PM
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        set<int> pos;
        for (int i=0 ; i<s.size() ; i++) 
            if (s[i] == c)  
                pos.insert(i);
        vector<int> ans;
        for (int i=0 ; i<s.size() ; i++) {
            auto right = pos.upper_bound(i);
            auto left = prev(right);
            int curr = INT_MAX;
            if (right != pos.end()) curr = *right - i;
            if (right != pos.begin()) curr = min(curr , i - *left);
            ans.push_back(curr);
        }
        return ans;
    }
};