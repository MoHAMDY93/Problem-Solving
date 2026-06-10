// Last updated: 6/10/2026, 7:26:19 PM
class Solution {
public:
    string reverseWords(string s) {
        /*
            two pointers:
            strat from the beginning with l & r, when we windows the first word we ush it in a reversed form
            like "eulb" and then move the window to the next word and so on 
            then reverse the whole string 
        */
        int l=0 , r = 0 , n = s.size();
        string ans , curr = "";
        while(r < n) {
            while(s[r] == ' ' && r < n) r++;
            if(r != n && !ans.empty()) ans += " ";
            while(s[r] != ' ' && r < n) curr.push_back(s[r++]);
            reverse(curr.begin() , curr.end());
            cout << curr << "\n";
            ans += curr;
            curr = "";
        }   
        cout << ans << "\n";
        reverse(ans.begin() , ans.end());
        return ans;
    }
};