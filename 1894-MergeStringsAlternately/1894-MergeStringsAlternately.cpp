// Last updated: 6/10/2026, 7:19:29 PM
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0 , j = 0;
        while(i < word1.length() && j < word2.length()) {
            ans += word1[i++];
            ans += word2[j++];
        }
        if(i < word1.length())
            while(i < word1.length())
                ans += word1[i++];
        else
            while(j < word2.length())
                ans += word2[j++];
        // cout<<ans<<endl;;
        return ans;
    }
};