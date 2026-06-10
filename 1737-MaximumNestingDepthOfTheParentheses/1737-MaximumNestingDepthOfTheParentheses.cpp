// Last updated: 6/10/2026, 7:20:13 PM
class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0 , ans = 0;
        for(char c : s) {
            if(c == '(') 
                ans = max(++cnt , ans);
            else if(c == ')') 
                cnt--;
        }
        return ans;
    }
};