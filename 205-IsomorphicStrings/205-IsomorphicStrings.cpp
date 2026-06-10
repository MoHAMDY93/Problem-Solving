// Last updated: 6/10/2026, 7:25:46 PM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char , char>map_s , map_t;
        for(int i=0 ; i<s.size() ; i++) {
            char s_c = s[i] , t_c = t[i];
            if(map_s.find(s_c) != map_s.end()) {
                if(map_s[s_c] != t_c) {
                    return false;
                }
            }
            else {
                if(map_t.find(t_c) != map_t.end()) {
                    return false;
                }
                map_s[s_c] = t_c;
                map_t[t_c] = s_c;
            }
        }
        return true;    
    }
};