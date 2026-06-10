// Last updated: 6/10/2026, 7:28:24 PM
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown; // Change direction
            }
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};