// Last updated: 6/10/2026, 7:28:17 PM
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string n = to_string(x);
        for(int i=0 , j = n.size()-1 ; i<j ; i++ , j--) {
            if(n[i] != n[j]) return false;
        }
        return true;
    }
};