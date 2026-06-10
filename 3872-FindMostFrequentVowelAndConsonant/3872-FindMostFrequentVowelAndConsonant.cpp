// Last updated: 6/10/2026, 7:11:34 PM
class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};
        int V = 0 , C = 0;
        for(auto c : s) {
            freq[c - 'a']++;
        }
        string t = "aeiou";
        for(auto c = 'a' ; c <= 'z' ; c++) {
            if(t.find(c) != string::npos) V = max(V , freq[c-'a']);
            else C = max(C , freq[c-'a']);
        }
        return V + C;
    }
};