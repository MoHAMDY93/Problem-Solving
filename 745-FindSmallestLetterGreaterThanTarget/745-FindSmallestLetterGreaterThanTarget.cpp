// Last updated: 6/10/2026, 7:23:54 PM
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = 26 + 'a';
        for(auto c : letters) {
            if(c > target && c < ans) ans = c;
        }
        return ans == 26 + 'a' ? letters[0] : ans;
    }
};