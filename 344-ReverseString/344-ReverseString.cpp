// Last updated: 6/10/2026, 7:25:06 PM
class Solution {
public:
    void reverseString(vector<char>& s) {
        const int n=s.size();
        for(int i=0, j=n-1; i<j; i++, j--)
            swap(s[i], s[j]);
    }
};