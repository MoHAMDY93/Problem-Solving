// Last updated: 6/10/2026, 7:18:18 PM
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int m = n / rows;
        string ans;
        for (int c=0 ; c<m ; c++) {
            int i=0 , j = c;
            while (i < rows && j < m) {
                ans.push_back(encodedText[i*m + j]);
                i++ , j++;
            }
        }
        while (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};