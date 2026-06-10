// Last updated: 6/10/2026, 7:16:19 PM
class Solution {
public:
    int appendCharacters(string s, string t) {
        int ptr = 0 , ans;
        for(int i=0 ; i<s.size() ; i++) {
            if(s[i] == t[ptr]) {
                ptr++;
                // cout<<"in"<<endl;
            }
        }
        ans = t.size() - ptr;
        return ans;
    }
};