// Last updated: 6/10/2026, 7:28:25 PM
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for(int i=0; i<s.size(); i++){
            string temp;
            for(int j=i; j<s.size(); j++){
                temp+=s[j];
                if(equal(temp.begin(), temp.begin() + temp.size()/2, temp.rbegin()))
                    ans = (temp.size()>ans.size())? temp : ans;
            }
        }
        return ans;  
    }
};