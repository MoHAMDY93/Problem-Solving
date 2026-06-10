// Last updated: 6/10/2026, 7:13:15 PM
class Solution {
public:
    string word = "a";
    char kthCharacter(int k) {
        if(word.length() >= k)
            return word[k-1];
        string toAppend;
        for(char c : word){
            toAppend += (c < 'z' ? c += 1 : 'a');
        }
        word += toAppend;
        return kthCharacter(k);   
    }
};