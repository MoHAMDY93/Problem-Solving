// Last updated: 6/10/2026, 7:27:22 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool flag = false;
        int length=0;
        for(int i=s.size()-1 ; i>=0 ; i--) {
            if(s[i] == ' ' && !flag) {
                continue;
            }
            else if(s[i] != ' ') 
                flag = true;
            else if(flag && s[i] == ' '){
                break;
            }
            length++;
        }
        return length;
    }
};