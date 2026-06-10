// Last updated: 6/10/2026, 7:10:12 PM
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<int , int> mp;
        vector<int> freq(26 , 0);
        for(auto c : s) freq[c-'a']++;
        for(auto i : freq) {
            if(i > 0) mp[i]++;
        }
        int mx = 0 , f = -1;
        for(auto [fre , v] : mp) {
            if(v > mx) mx = v , f = fre;
            if(v == mx && fre > f) f = fre;
        }
        string ans;
        for(int i=0; i<26; i++) {
            if(freq[i] == f) ans += (char)('a' + i);
        }
        return ans;
    }
};