class Solution {
public:
    int minInsertions(string s) {
        int bal = 0 , close = 0 , ans = 0;
        for (auto c : s) {
            if (c == '(') {
                // if the prev open one not closed yet
                if (close == 1) ans++ , bal-- , close = 0;
                bal++;
            } else {
                if (bal == 0) ans++ , bal++;
                close++;
                if (close == 2) bal-- , close = 0;
            }
        }
        return ans + (2 * bal - close);
    }
};