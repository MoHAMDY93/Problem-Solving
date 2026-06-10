// Last updated: 6/10/2026, 7:26:38 PM
class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (char c : s) {
            if (isalnum(c)) t.push_back(tolower(c));
        }
        cout << t << "\n";
        int n = t.size();
        for (int i = 0 , j = n-1 ; i<n/2 ; i++ , j--) {
            if (t[i] != t[j]) return false;
        }
        return true;
    }
};