// Last updated: 6/10/2026, 7:15:16 PM
class Solution {
public:
    string sortVowels(string s) {
        vector<int> freq(10 , 0);
        function<bool(char)> isVowel = [&](char c) {
            char x = tolower(c);
            return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'); 
        };
        string t = "AEIOUaeiou";
        map<char , int> mp;
        for(int i=0 ; i<10 ; i++) mp[t[i]] = i;
        for(auto c : s) {
            if(isVowel(c)) {
                freq[mp[c]]++;
            }
        }
        string ans;
        int idx = 0;
        for(char c : s) {
            if(isVowel(c)) {
                while(freq[idx] == 0) idx++;
                ans.push_back(t[idx]) , freq[idx]--;
            }
            else ans.push_back(c);
        }
        return ans;
    }
};