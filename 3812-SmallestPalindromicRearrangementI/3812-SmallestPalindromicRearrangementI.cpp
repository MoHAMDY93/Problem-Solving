// Last updated: 6/10/2026, 7:11:56 PM
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26 , 0);
        for(auto c : s) freq[c - 'a']++;
        string top , mid , bottom;
        for(int i=0 ; i<26 ; i++) {
            int cnt = freq[i];
            char curr = 'a' + i;
            if(cnt & 1) {
                mid.push_back(curr);
                cnt--;
                for(int i=0 ; i<cnt/2 ; i++) top.push_back(curr) , bottom.push_back(curr);
            } else {
                for(int i=0 ; i<cnt/2 ; i++) top.push_back(curr) , bottom.push_back(curr);
            }
        }
        reverse(begin(bottom) , end(bottom));
        return top + mid + bottom;
    }
};