// Last updated: 6/10/2026, 7:09:59 PM
class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size();
        string ans = s;
        for(int i=1 ; i<n ; i++) {
            string fst = s.substr(0 , i);
            string lst = s.substr(i);
            string fstR = fst , lstR = lst;
            reverse(fstR.begin() , fstR.end());
            reverse(lstR.begin() , lstR.end());
            ans = min({ans , fst.append(lstR) , fstR.append(lst)});
        }
        reverse(s.begin() , s.end());
        ans = min(ans , s);
        return ans;
    }
};