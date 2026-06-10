// Last updated: 6/10/2026, 7:15:08 PM
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> freq1(26 , 0) , freq2(26 , 0);
        for (int i=0 ; i<s1.size() ; i++) {
            (i & 1 ? freq1 : freq2)[s1[i] - 'a']++;
        }
        for (int i=0 ; i<s2.size() ; i++) {
            (i & 1 ? freq1 : freq2)[s2[i] - 'a']--;
        }
        for (int i=0 ; i<26 ; i++) if (freq1[i] != 0 || freq2[i] != 0) return false;
        return true;
    }
};